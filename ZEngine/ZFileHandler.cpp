//-----------------------------------------------------------
// ZFileHandler.cpp
//-----------------------------------------------------------

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ZFileHandler.h"

using namespace ZEngine;

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZFileHandler :: CZFileHandler(const std::string & p_sFilePath, FileOpenFlag p_eFlag)
	: m_bIsOpen(false), m_sFilePath("")
{
	m_Fstream.open(p_sFilePath, GetOpenMode(p_eFlag));

	if (m_Fstream.is_open())
	{
		m_sFilePath = p_sFilePath;
		m_bIsOpen = true;
	}
	else
	{
		assert(0 && "Could not open file");
	}
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
CZFileHandler :: ~CZFileHandler()
{
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
std::fstream::open_mode CZFileHandler :: GetOpenMode(FileOpenFlag p_eOpenFlag)
{
	switch (p_eOpenFlag)
	{
	case ZEngine::FileOpenFlag::e_OpenFlag_Read:
		return std::fstream::in;
	case ZEngine::FileOpenFlag::e_OpenFlag_Write:
		return std::fstream::out;
	case ZEngine::FileOpenFlag::e_OpenFlag_RW:
		return ( std::fstream::in | std::fstream::out );
	case ZEngine::FileOpenFlag::e_OpenFlag_RW_End:
		return (std::fstream::in | std::fstream::out | std::fstream::ate );
	}
	return (std::fstream::in | std::fstream::out);
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZFileHandler::FileExists(const std::string & p_sFilePath)
{
	struct stat statBuff;
	int bResult;

	bResult = stat(p_sFilePath.c_str(), &statBuff);

	return bResult == 0;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZFileHandler :: Open(const std::string & p_sFilePath, FileOpenFlag p_eFlag)
{
	if (m_Fstream.is_open())
	{
		if (m_sFilePath.compare(p_sFilePath))
		{
			return true;
		}
		else
		{
			m_Fstream.close();
		}
	}

	m_Fstream.open(p_sFilePath, GetOpenMode(p_eFlag));
	if (!m_Fstream.is_open())
	{
		return false;
	}
	m_sFilePath = p_sFilePath;
	return true;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
void CZFileHandler :: Close()
{
	if (m_Fstream.is_open())
		m_Fstream.close();
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
bool CZFileHandler :: Write(const std::string & p_sStr)
{
	if (m_Fstream.is_open())
	{
		m_Fstream << p_sStr << std::endl;
		m_Fstream.flush();
		return !m_Fstream.bad();
	}
	return false;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
int CZFileHandler :: Read(char * p_sBuffer, unsigned int p_uNbCharToRead)
{
	if (m_Fstream.is_open())
	{
		m_Fstream.read(p_sBuffer, p_uNbCharToRead);
		if (m_Fstream.bad())
			return -1;
		return (int) m_Fstream.gcount();
	}
	return -1;
}

//-----------------------------------------------------------
//
//-----------------------------------------------------------
int CZFileHandler :: ReadLine(char * p_sBuffer, unsigned int p_uNbCharToRead)
{
	if (m_Fstream.is_open())
	{
		m_Fstream.getline(p_sBuffer, p_uNbCharToRead);
		if (m_Fstream.bad())
			return -1;
		return (int) m_Fstream.gcount();
	}
	return -1;
}