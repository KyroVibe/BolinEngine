#pragma once

#include "Bolin/Vector2.h"

namespace Bolin {
	class Camera {
	public:
		Camera() : Size(1.0), Position(0.0, 0.0) { }
		Camera(double size, Vector2 position) : Size(size), Position(position) { }

		double Size;
		Vector2 Position;
	};
}
