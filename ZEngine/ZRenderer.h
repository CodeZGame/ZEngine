//-----------------------------------------------------------
// ZRenderer.h
//-----------------------------------------------------------

#pragma once

#include <vector>

#define MAX_DRAWABLE_INSTANCES 2048


namespace ZEngine
{
	class ZInstance;
	class CZEngineWindow;

	class CZRenderer
	{
	private:
		CZEngineWindow * m_pWindowOwner;
		std::vector<ZInstance *> m_pfDrawableInstances;

	public:
		CZRenderer();
		CZRenderer(CZEngineWindow * p_pWindowOwner);
		~CZRenderer();

		void SetWindowOwner(CZEngineWindow * p_pWindowOwner);

		void Process();

		void AddDrawableInstance(ZInstance * p_pZInstance);

		void RemoveInstanceFromDrawingProcess(ZInstance * p_pZInstance);
	};
}