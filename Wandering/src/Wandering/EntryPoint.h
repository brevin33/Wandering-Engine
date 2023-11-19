#pragma once

#ifdef WAND_PLATFORM_WINDOWS

extern Wandering::Application* Wandering::CreateApplication();

int main() {
	auto app = Wandering::CreateApplication();
	app->Run();
	delete app;
}

#endif