#include "Engine.h"
#include "Input/Mouse.h"

#include "Input/Tastatura.h"

int Engine::latime = 1920;
int Engine::inaltime = 1080;

GLFWwindow* Engine::window = NULL;

float Engine::delta = 0;

Engine::Engine() //constructor pt engine
{

}

Engine::~Engine()
{

}

bool Engine::InitEngine(char * fereastraTitlu)
{
	if (!glfwInit())
	{
		cout << "Eroare initializare GLFW";
		return false;
	}

	window = glfwCreateWindow(latime, inaltime, fereastraTitlu, NULL, NULL); //dimensiunea ferestrei
	if (window == NULL)
	{
		cout << "Eroare creare fereastra";
		return false;
	}

	//OPENGL
	glfwMakeContextCurrent(window); //va fi un pointer catre o fereastra curenta astfel incat Opengl va lucra cu acel pointer
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glfwSwapInterval(1);
	//double Buffering, doua buffere, ce este afisat in mod curent si al doilea buffer ce este de randat (swap buffer cand este terminat de afisat prima scena)
	//altfel ar fi flickering

	glfwSetCursorPosCallback(window, Mouse::posMouseCall);

	glfwSetMouseButtonCallback(window, Mouse::butonMouseCall);

	glfwSetKeyCallback(window, Tastatura::KeyCallback);


	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());//este centrat intotdeana, ofera un cotnext;

	int xPos = (mode->width - latime) / 2; //punct central pe ecran, adica centrarea ferestrei
	int yPos = (mode->height - inaltime) / 2;

	glfwSetWindowPos(window, xPos, yPos);

	//GL - setarea viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);  //cum sunt gestionate matricele in OPENGL
	glLoadIdentity();

	glOrtho(0, width, 0, height, -10, 10); // -10 ofera o adancime pt scena, in fucntie de cate layer-uri vrem sa folosim
	glDepthRange(-10, 10);

	glMatrixMode(GL_MODELVIEW);

	//pentru imagini transparente Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Refresh()
{
	double TimpCurent = glfwGetTime();
	delta = (TimpCurent - lastTime);
	lastTime = TimpCurent;
	glfwPollEvents(); //va inregistra toate evenimentele din stiva
}

void Engine::incepeRender()
{
	//nu vrem sa rescriem peste fiecare buffer de fiecare data, ci sa fie realizat un clear buffer
	glClearColor(0, 1, 1, 1); //clear back buffer cu o culoare
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //vom crea o masca pentru clear;

	//glfwSwapBuffers(window);
}

void Engine::termRender()
{
	glfwSwapBuffers(window); //orice este randat dupa swap buffers nu poate fi desenat, acesta trebuie sa se intample intre glclear si inainte de swapbuffers
}

float Engine::getDelta()
{
	return (float)delta;
}