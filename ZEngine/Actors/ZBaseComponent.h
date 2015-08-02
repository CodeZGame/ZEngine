//-----------------------------------------------------------
// ZBaseComponent.h
//-----------------------------------------------------------

#pragma once

namespace ZEngine
{
	class CZBaseComponent
	{
	private:
		bool	m_bIsActive;

	public:

		bool GetActive() const;
		void SetActive(bool p_bIsActive);
	};
}