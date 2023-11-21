#include <Wandering.h>

class App : public Wandering::Application {

public:
	App() {
	}

	~App() {

	}
};


Wandering::Application* Wandering::CreateApplication() {
	return new App();
}