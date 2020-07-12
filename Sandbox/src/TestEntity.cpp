#include "TestEntity.h"

using namespace Bolin;

TestEntity::TestEntity(): Entity("name"), _rotationSpeed(0) {
	RenderBody r = RenderBody();
	r.Fill = false;
	r.Vertices.push_back(Vector2(-1, 0));
	r.Vertices.push_back(Vector2(0, 1));
	r.Vertices.push_back(Vector2(1, 0));
	r.Vertices.push_back(Vector2(0, -1));
	_body = r;
}

TestEntity::~TestEntity() { }

void TestEntity::Tick() {
	static long lastTick = Utility::GetMilliseconds();;
	static double deltaT;
	deltaT = Utility::GetMilliseconds() - lastTick;
	Rotation += deltaT * (_rotationSpeed / 1000.0);
	lastTick = Utility::GetMilliseconds();
}