//-----------------------------------------------------------
// ZFileHandler.h
//-----------------------------------------------------------

#pragma once

#include <string>
#include <fstream>

namespace ZEngine
{
	enum class FileOpenFlag
	{
		e_OpenFlag_Read,				//Open file in read mode only
		e_OpenFlag_Write,				//Open file in write mode only
		e_OpenFlag_RW,					//Open file in read/write mode
		e_OpenFlag_RW_End,				//Open file in read/write mode, and set cursor at the end
	};

	class CZFileHandler
	{
	protected:
		std::string m_sFilePath;
		std::fstream m_Fstream;
		bool m_bIsOpen;

		std::fstream::open_mode GetOpenMode(FileOpenFlag p_eOpenFlag);

	public:
		CZFileHandler(const std::string & p_sFilePath, FileOpenFlag p_eFlag);
		~CZFileHandler();

		static bool FileExists(const std::string & p_sFilePath);

		bool Open(const std::string & p_sFilePath, FileOpenFlag p_eFlag);
		void Close();

		bool Write(const std::string & p_sStr);

		int Read(char * p_sBuffer, unsigned int p_uNbCharToRead);

		int ReadLine(char * p_sBuffer, unsigned int p_uNbCharToRead);
	};
}