#include "Texture.h"

Texture::Texture()
{
	id = -1; //setarea texturii prin opengl
}

Texture::Texture(int _id)
{
	id = _id;

	if (!getTexture())
	{
		cout << "Incarcare imagine gresita" << id ;

	}
}

Texture::Texture(string path)
{
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y); //orice alpha va fi multiplicat cu acea culoare bitwise or
	if(!getTexture())
	{
		cout << "Incarcare imagine gresita" << path;

	} //daca poate incarca sau nu textura
}

int Texture::getIndex()
{
	return id;
}

int Texture::getLatime()
{
	return latime;
}

int Texture::getInaltime()
{
	return inaltime;
}

bool Texture::getTexture()
{
	//textura incarcata de catre SOIL va fi referinta de catre acest ID
	if (id > 0)
	{
		int mipLevel = 0; //cu cat nr mai mare, e dat de compresie; 
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &latime);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &inaltime);
		return true;
	}
	return false;
}