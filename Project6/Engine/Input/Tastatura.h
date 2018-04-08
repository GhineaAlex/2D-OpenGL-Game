#include "GLFW/glfw3.h"
#include <iostream>


using namespace std;

class Tastatura
{
public:
	static void KeyCallback(GLFWwindow * window, int key, int code, int actiune, int mods);

	static bool keyJos(int key);
	static bool keySus(int key);
	static bool key(int key);
private:
	static bool keys[];
	static bool keysJos[];
	static bool keysSus[];
};

