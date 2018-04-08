#pragma once

#ifndef TWITCH_TEXTURE
#define TWITCH_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"
#include <string>
#include <iostream>

using namespace std;

class Texture
{
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int getIndex();
	int getLatime();
	int getInaltime();

private:
	bool getTexture();

	int id;
	int latime, inaltime;


};

#endif