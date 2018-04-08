#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE
#include <iostream>
#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")


using namespace std;
class Engine
{
public:
	static int latime;
	static int inaltime;
	static float getDelta();
	Engine();
	~Engine();

	bool InitEngine(char * fereastraTitlu); //initializarea engine-ului/fereastra

	void Refresh();
	void incepeRender();
	void termRender();
private:
	static GLFWwindow * window; //pointer catre fereastra static

	static float delta; //nu vom instantia inca un engine cu un nou engine, deci va fi de tip static
	float lastTime;
};

#endif