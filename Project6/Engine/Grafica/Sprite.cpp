#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite()
{
	pos = Vector3p(0);
	rotatie = 0;

	scale = Vector3p(1);
	size = Vector3p(0);
	viteza = 200;
	texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	pos = Vector3p(0);
	rotatie = 0;
	scale = Vector3p(1);
	size = Vector3p((float)texture.getLatime(), (float)texture.getInaltime(), 1);

	viteza = 200;
}

Sprite::Sprite(string imagePath, Vector3p v)
{
	texture = Texture(imagePath);
	pos = v; //folosim constructorul de copiere aici
	scale = Vector3p(1);
	size = Vector3p((float)texture.getLatime(), (float)texture.getInaltime(), 1);

	rotatie = 0;
	viteza = 200;
}

void Sprite::Refresh()
{
	
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getIndex()); //bind textura la acel ID
	glLoadIdentity();
	//Translate - rotate - scale

	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rotatie, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	//pt render
	glColor4f(1, 1, 1, 1); //pentru ca avem si alpha
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2i(-texture.getLatime() / 2, -texture.getInaltime() / 2); //colt stanga jos 0, 0 coord

	glTexCoord2f(1, 0);
	glVertex2i(texture.getLatime() / 2, -texture.getInaltime() / 2); //colt stanga jos 0, 0 coord

	glTexCoord2f(1, 1);
	glVertex2i(texture.getLatime() / 2, texture.getInaltime() / 2); //colt stanga jos 0, 0 coord 

	glTexCoord2f(0, 1);
	glVertex2i(-texture.getLatime()/ 2 , texture.getInaltime() / 2);

	
	glEnd();
	//practic fiecare textura este stretched in fiecare colt al imaginii
	glDisable(GL_TEXTURE_2D);
}

void Sprite::setViteza(float x)
{
	viteza = x;
}

void Sprite::setVitezaCu(float x)
{
	viteza += x;
}

void Sprite::TranslateTo(Vector3p v)
{
	pos = v;
}

void Sprite::TranslateCu(Vector3p v)
{
	pos = pos + (v * Engine::getDelta()); //trebuie sa ia in considerare delta time
}

void Sprite::TranslateStg()
{
	pos = pos - Vector3p((viteza * Engine::getDelta()), 0, 0);
}

void Sprite::TranslateDr()
{
	pos = pos + Vector3p((viteza * Engine::getDelta()), 0, 0);
}

void Sprite::TranslateSus()
{
	pos = pos + Vector3p(0, (viteza * Engine::getDelta()), 0);
}

void Sprite::TranslateJos()
{
	pos = pos - Vector3p(0, (viteza * Engine::getDelta()), 0);
}

void Sprite::RotateLa(float x)
{
	rotatie = x;
}

void Sprite::RotitCu(float x)
{
	rotatie += (x * Engine::getDelta());
}

void Sprite::setScalare(float x)
{
	scale = Vector3p(x);
}

void Sprite::setScalare(Vector3p v)
{
	scale = v;
}

Vector3p * Sprite::getPos() 
{
	return &pos;
}

float * Sprite::getRotatie()
{
	return &rotatie;
}

Vector3p * Sprite::getScalare() 
{
	return &scale;
}
Vector3p * Sprite::getSize()
{
	return &size;
}

