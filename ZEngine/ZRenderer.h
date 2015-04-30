//-----------------------------------------------------------
// ZRenderer.h
//-----------------------------------------------------------

#pragma once

#include <vector>

#define MAX_DRAWABLE_INSTANCES 2048

namespace ZEngine
{
	class CZInstance;
	class CZWindow;

	class CZRenderer
	{
	private:
		CZWindow * m_pWindowOwner;
		std::vector<CZInstance *> m_pfDrawableInstances;
		unsigned int m_uNbInstances;

	public:
		CZRenderer();
		CZRenderer(CZWindow * p_pWindowOwner);
		~CZRenderer();

		void SetWindowOwner(CZWindow * p_pWindowOwner);

		void Process();

		void ProcessDrawDebug();

		void AddDrawableInstance(CZInstance * p_pZInstance);

		void RemoveDrawableInstance(CZInstance * p_pZInstance);
	};
}