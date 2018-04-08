#include "Joc.h"
//
#include <iostream>

using namespace std;

Joc::Joc()
{
}

Joc::Joc(Sprite _sprite)
{
	sprite = _sprite;
	rb.Init(0.8f, -0.01, sprite.getPos(), sprite.getRotatie(), sprite.getScalare(), sprite.getSize()); //fercare, gravitatie
}

void Joc::Refresh()
{
	sprite.Refresh();
	rb.Refresh();
}

void Joc::Render()
{
	sprite.Render();
	rb.Render(Vector3p(0,0,0));
}

Sprite & Joc::getSprite()
{
	return sprite;
}

Rigid & Joc::getRigid()
{
	return rb;
}