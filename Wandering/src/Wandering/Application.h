#pragma once
#include "wdpch.h"
#include "Core.h"
namespace Wandering {

	class WANDERING_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};
	
	// made by client
	Application* CreateApplication();
}