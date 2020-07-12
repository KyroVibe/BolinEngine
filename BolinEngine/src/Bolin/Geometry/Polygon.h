#pragma once

#include <vector>

#include "Bolin/Vector2.h"
#include "Bolin/Graphics/RenderBody.h"

struct Polygon {
public:
	Polygon() { }
	Polygon(RenderBody& body): Vertices(body.Vertices) { }

	std::vector<Vector2> Vertices;
};