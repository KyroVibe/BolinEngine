#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>
#include <stdlib.h>

#include "Bolin/Graphics/Point.h"
#include "Bolin/Vector2.h"

using namespace std::chrono;

namespace Bolin {
	class Utility {
	public:
		static long GetMilliseconds() {
			return (long)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		}

		static int Rand() {
			return rand() + GetMilliseconds();
		}

		static Point ToPoint(Vector2 vector) {
			return Point(vector.X, vector.Y);
		}
	};
}