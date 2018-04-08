//display propriu-zis a texturii in fereastra
#pragma once

#ifndef Proiect
#define Proiect

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Mate/Vector3p.h"
#include <string>
#include <iostream>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3p _pos);

	void Refresh();
	void Render();

	void setViteza(float x);
	void setVitezaCu(float x);

	void TranslateTo(Vector3p v); //muta
	void TranslateCu(Vector3p v); //muta cu 

	void TranslateStg(); //merge stg
	void TranslateDr();  //mers dr

	void TranslateSus(); 
	void TranslateJos();

	void RotateLa(float x);
	void RotitCu(float x);

	void setScalare(float x);
	void setScalare(Vector3p v);

	Vector3p * getPos();
	float * getRotatie();
	Vector3p * getScalare();
	Vector3p * getSize();

private:
	Texture texture;

	float viteza;

	Vector3p pos;
	Vector3p scale;
	Vector3p size;
	float rotatie;
};

#endif