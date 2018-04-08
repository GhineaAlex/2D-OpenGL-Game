#pragma once

#include "GLFW/glfw3.h"

class Mouse
{
public:
	static void posMouseCall(GLFWwindow * window, double _x, double _y);
	static void butonMouseCall(GLFWwindow * window, int buton, int actiune, int mods); //actiune daca a fost apasat sau nu, mods

	static double getMouseX();
	static double getMouseY();

	static bool butonApasat(int buton); //este apasat
	static bool butonSus(int buton); //a fost tocmai eliberat
	static bool buton(int buton);

private:
	static double x;
	static double y;

	//vom crea o matrice de boolene pentru a incarca mouse-ul, poate lua doar valori 1 sau 0 daca este apasat sau nu

	static bool butoane[];
	static bool butoaneApasat[];
	static bool butoaneSus[]; //butonul a fost tocmai eliberat, adica a fost apasat


};