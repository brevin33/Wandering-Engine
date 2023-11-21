#pragma once

#ifdef WD_PLATFORM_WINDOWS

extern Wandering::Application* Wandering::CreateApplication();

class testEvent {
public:
	std::string hi = "hello world";
};



void testEventListener(testEvent e) {
	std::cout << e.hi << std::endl;
}

int main() {
	Wandering::Log::Init();
	auto app = Wandering::CreateApplication();
	WD_CORE_INFO("hi");

	void(*e)(testEvent) = testEventListener;
	Wandering::EventHandler<testEvent>::addListener(e);
	testEvent t;
	Wandering::EventHandler<testEvent>::trigger(t);

	app->Run();
	delete app;
}

#endif