#pragma once

#include <GLFW/glfw3.h>

class Color {
public:
    Color() : R(0.0f), G(0.0f), B(0.0f), A(0.0f) { }
    Color(float r, float g, float b) : R(r), G(g), B(b), A(0.0f) { }
    Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(a) { }

    GLfloat R, G, B, A;
};