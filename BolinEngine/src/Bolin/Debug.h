#pragma once

#include <iostream>

#define BOLIN_DEBUG

#ifdef BOLIN_DEBUG
#define LOG(x) std::cout << "[INFO] " << x << std::endl;
#define WARN(x) std::cout << "[WARNING] " << x << std::endl;
#else
#define LOG(x)
#define WARN(x)
#endif