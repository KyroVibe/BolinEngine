#include <Bolin.h>
#include <Bolin/EntryPoint.h>

#include "MainLevel.h"

using namespace Bolin;

#define RESIZEABLE 1

class Sandbox : public Application {
public:
	Sandbox(): Application(800, 600, "Sandbox Application", new MainLevel(), 60, new Camera(5, Vector2(0, 0))) {

	}

	~Sandbox() {

	}
};

Bolin::Application* Bolin::CreateApplication() {
	return new Sandbox();
}