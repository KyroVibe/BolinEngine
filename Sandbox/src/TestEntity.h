#pragma once

#include <Bolin.h>

using namespace Bolin;

class TestEntity: public Entity {
public:
	TestEntity();
	~TestEntity();

	void Tick();
private:
	double _rotationSpeed; // Degrees per second
};
