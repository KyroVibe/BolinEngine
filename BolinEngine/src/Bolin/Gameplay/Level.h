#pragma once

#include <string>
#include <vector>

#include "Bolin/Graphics/Window.h"
#include "Bolin/Gameplay/Entity.h"
#include "Bolin/Core.h"

namespace Bolin {
	class BOLIN_API Level {
	public:
		Level(std::string levelName);
		virtual ~Level();

		void Tick();
		void Render(Window* window);

		std::vector<Entity*>& GetEntities() { return _entities; }
	protected:
		std::vector<Entity*> _entities;
	private:
		std::string _levelName;
	};
}