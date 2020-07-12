#include "Bolin/Interaction/Input.h"

void Input::ProcessInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// LOG("Key: " << key << std::endl << "Action: " << action);
	static int* keyStates = Instance()->KeyStates;
	if (action > 0) {
		if (keyStates[key] == 0)
			keyStates[key] = 1;
		else if (keyStates[key] == 1)
			keyStates[key] = 2;
	}
	else {
		keyStates[key] = 3;
	}
}

int Input::GetKeyState(int key) {
	if (key > 255 || key < 0)
		throw 20;
	if (Instance()->KeyStates == nullptr)
		return -1;

	static int keyState;
	keyState = Instance()->KeyStates[key];
	Instance()->KeyStates[key] = 0;
	return keyState;
}