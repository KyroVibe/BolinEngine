#include "MainLevel.h"
#include "TestEntity.h"

using namespace Bolin;

MainLevel::MainLevel(): Level("MainLevel") {
	_entities.push_back(new TestEntity());
}

MainLevel::~MainLevel() { }