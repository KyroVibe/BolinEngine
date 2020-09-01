#define _USE_MATH_DEFINES

#include <cmath>

#include "Bolin/Gameplay/Level.h"
#include "Bolin/Graphics/RenderBody.h"

namespace Bolin {
	Level::Level(std::string levelName): _levelName(levelName) { }
	Level::~Level() {
		for (int i = 0; i < _entities.size(); i++) {
			if (_entities.at(i) != nullptr)
				delete _entities.at(i);
		}
	}

	void Level::Tick() {
		for (int i = 0; i < _entities.size(); i++) {
			_entities.at(i)->Tick();
		}
	}

	// rotation -> degrees
	std::vector<Point> GetDrawablePoints(Vector2 position, double rotation, std::vector<Vector2> vertices, Window* window) {
		std::vector<Point> points;
		static Vector2 originalVector;
		static Vector2 moddedVector;
		for (int i = 0; i < vertices.size(); i++) {
			originalVector = vertices.at(i);

			// Rotation
			double radians = rotation * (M_PI / 180.0);
			double s = -sin(radians); // So it will rotate clockwise
			double c = cos(radians);
			moddedVector.X = (originalVector.X * c) - (originalVector.Y * s);
			moddedVector.Y = (originalVector.X * s) + (originalVector.Y * c);

			// Translation
			moddedVector = moddedVector + position;

			points.push_back(window->CastVector(moddedVector));
		}
		return points;
	}

	void Level::Render(Window* window) {

		// Test render
		/*std::vector<Point> points;
		points.push_back(Point(0.5, 0.0));
		points.push_back(Point(0.0, 0.5));
		points.push_back(Point(-0.5, 0.0));
		points.push_back(Point(0.0, -0.5));
		window->DrawPolygon(points, true);*/

		std::vector<Entity*>& entities = GetEntities();
		RenderBody body;
		for (int i = 0; i < entities.size(); i++) {
			LOG("Drawing entity");
			Entity* ent = entities.at(i);
			body = ent->GetBody();
			std::vector<Point> points = GetDrawablePoints(ent->Position, ent->Rotation, body.Vertices, window);
			for (Point p : points) {
				LOG("(" << p.X << ", " << p.Y << ")");
			}
			window->DrawPolygon(points, body.Fill);
		}
	}
}