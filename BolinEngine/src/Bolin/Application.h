#pragma once

#include "Bolin/Core.h"
#include "Bolin/Graphics/Window.h"
#include "Bolin/Gameplay/Level.h"

namespace Bolin {

	class BOLIN_API Application
	{
	public:
		Application(int width, int height, std::string windowName, Level* defaultLevel, int renderFps, Camera* camera);
		virtual ~Application();

		Window* GetWindow() { return _window; }

		void SetCurrentLevel(Level* level);
		Level* GetCurrentLevel();

		void Run();

		void Tick();
		void Render(Window *window);
	private:
		bool _halt = false;
		Window* _window;
		Level* _currentLevel;
		int _renderFps;
	};

	// Define in client;
	Application* CreateApplication();
}
