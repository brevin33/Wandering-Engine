#pragma once

#ifdef WD_PLATFORM_WINDOWS

extern Wandering::Application* Wandering::CreateApplication();

int main() {
	Wandering::Log::Init();

	auto app = Wandering::CreateApplication();
	app->Run();
	delete app;
}

#endif