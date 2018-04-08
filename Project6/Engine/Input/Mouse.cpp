#include "Mouse.h"
#include <iostream>


using namespace std;



bool Mouse::butoane[GLFW_MOUSE_BUTTON_LAST] = { 0 };

bool Mouse::butoaneApasat[GLFW_MOUSE_BUTTON_LAST] = { 0 }; //cate butoane utilizate

bool Mouse::butoaneSus[GLFW_MOUSE_BUTTON_LAST] = { 0 };

double Mouse::x = 0;
double Mouse::y = 0;
void Mouse::posMouseCall(GLFWwindow * window, double _x, double _y)
{
	int height, width;

	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Mouse::butonMouseCall(GLFWwindow * window, int buton, int actiune, int mods)
{
	if (buton < 0)
	{
		return;
	}

	if (actiune != GLFW_RELEASE && butoane[buton] == false)
	{
		butoaneApasat[buton] = true;
		butoaneSus[buton] = false;

	}

	if (actiune == GLFW_RELEASE && butoane[buton] == true)
	{
		butoaneApasat[buton] = false;
		butoaneSus[buton] = true;

	}

	butoane[buton] = actiune != GLFW_RELEASE;

}

double Mouse::getMouseX()
{
	return x;
}

double Mouse::getMouseY()
{
	return y;
}

bool Mouse::butonApasat(int buton)
{
	bool x = butoaneApasat[buton];
	butoaneApasat[buton] = false;
	return x;
}

bool Mouse::butonSus(int buton)
{
	bool x = butoaneSus[buton];
	butoaneSus[buton] = false;
	return x;
}

bool Mouse::buton(int buton)
{
	return butoane[buton];
}