#include "Tastatura.h"

bool Tastatura::keys[GLFW_KEY_LAST] = { 0 };
bool Tastatura::keysSus[GLFW_KEY_LAST] = { 0 };
bool Tastatura::keysJos[GLFW_KEY_LAST] = { 0 };

void Tastatura::KeyCallback(GLFWwindow * window, int key, int code, int actiune, int mods)
{
	if (key < 0)
	{
		return;
	}

	if (actiune != GLFW_RELEASE && keys[key] == false)
	{
		keysJos[key] = true;
		keysSus[key] = false;
	}

	if (actiune == GLFW_RELEASE && keys[key] == true)
	{
		keysJos[key] = false;
		keysSus[key] = true;
	}

	keys[key] = actiune != GLFW_RELEASE;
}

bool Tastatura::keyJos(int key)
{
	bool x = keysJos[key];
	keysJos[key] = false;
	return x;

}
bool Tastatura::keySus(int key)
{
	bool x = keysSus[key];
	keysSus[key] == false;
	return x;
}

bool Tastatura::key(int key)
{
	return keys[key];
}