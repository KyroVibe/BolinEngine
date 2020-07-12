#pragma once

#include <GLFW/glfw3.h>

class Point {
public:
    Point() : X(0.0f), Y(0.0f) { }
    Point(float x, float y) : X(x), Y(y) {
        if (X < -1.0f) X = -1.0f;
        if (X > 1.0f) X = 1.0f;
        if (Y < -1.0f) Y = -1.0f;
        if (Y > 1.0f) Y = 1.0f;
    }

    GLfloat X, Y;
};