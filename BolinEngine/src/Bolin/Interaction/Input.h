#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Bolin/Debug.h"

#define BOLIN_KEY_ABSENT 0
#define BOLIN_KEY_PRESSED 1
#define BOLIN_KEY_HELD 2
#define BOLIN_KEY_RELEASED 3

class Input {
public:
	static void ProcessInput(GLFWwindow* window, int key, int scancode, int action, int mods);
	static int GetKeyState(int key);

	int* KeyStates;
private:
	Input() { KeyStates = new int[256]; }
	~Input() { delete KeyStates; }

	static Input* Instance() {
		static Input instance;
		return &instance;
	}
};