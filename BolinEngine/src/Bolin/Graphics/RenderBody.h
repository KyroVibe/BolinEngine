#pragma once

#include <vector>

#include "Bolin/Vector2.h"

struct RenderBody {
public:
	bool Fill = true;
	std::vector<Vector2> Vertices;
};