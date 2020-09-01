#include "Bolin/Application.h"
#include "Bolin/Utility.h"

namespace Bolin {
	Application::Application(int width, int height, std::string windowName, Level* defaultLevel, int renderFps, Camera* cam) {
		_currentLevel = defaultLevel;
		_renderFps = renderFps;
		_window = new Window(width, height, windowName, cam);

		LOG("Startup");

		Run();
	}
	Application::~Application() {
		delete _currentLevel;
		delete _window;
	}

	void Application::SetCurrentLevel(Level* level) {
		delete _currentLevel;
		_currentLevel = level;
	}

	Level* Application::GetCurrentLevel() {
		return _currentLevel;
	}

	void Application::Run() {

		LOG("Running application");

		long lastMillis = Utility::GetMilliseconds();
		int cycleMs = 1000 / _renderFps;
		while (!_halt) {
			Tick();
			static long deltaT;
			deltaT = Utility::GetMilliseconds() - lastMillis;
			if (deltaT > cycleMs) {
				lastMillis = Utility::GetMilliseconds();
				// LOG("Render");
				_window->Clear();
				Render(_window);
				_window->Publish();
			}
			else {
				// LOG("Waiting: " << deltaT - cycleMs);
			}
			_window->PollEvents();
			_halt = _window->ShouldClose();
		}

		LOG("Application loop closing");
	}

	void Application::Tick() {
		_currentLevel->Tick();
	}

	void Application::Render(Window* window) {
		_currentLevel->Render(window);
	}
}