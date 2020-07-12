#pragma once

#include <string>

#include "Bolin/Graphics/RenderBody.h"
#include "Bolin/Vector2.h"
#include "Bolin/Core.h"

namespace Bolin {
	class BOLIN_API Entity {
	public:
		Entity(std::string entityName): _entityName(entityName),
			Position(0.0, 0.0), Rotation(0.0) { }
		Entity(std::string entityName, RenderBody renderBody, Vector2 position, double rotation):
			_entityName(entityName), _body(renderBody), Position(position), Rotation(rotation) { }
		virtual ~Entity() { }

		Vector2 Position;
		double Rotation;

		virtual void Tick() = 0;

		RenderBody& GetBody() { return _body; }
	protected:
		RenderBody _body;
		std::string _entityName;
	};
}