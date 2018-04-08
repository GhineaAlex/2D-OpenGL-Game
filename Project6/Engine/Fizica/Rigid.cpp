#include "Rigid.h"
#include "../Engine.h"

Rigid::Rigid()
{
	frecare = 1;

	//acceleratie.x = acceleratie.x * frecare;

	gravitatie = 0;

	//acceleratie.y = acceleratie.y - gravitatie * delta;

}

void Rigid::Init(float _frecare, float _gravitatie, Vector3p * _pos, float * _rotatie, Vector3p * _scalare,  Vector3p * _size)
{
	frecare = _frecare;
	gravitatie = _gravitatie;
	pos = _pos;
	scalare = _scalare;
	rotatie = _rotatie;
	size = _size;
}

void Rigid::Refresh()
{
	acceleratie.x *= frecare;
	acceleratie.y += gravitatie;
	
	*pos = *pos + (acceleratie * Engine::getDelta());
	
	
}

void Rigid::Render(Vector3p c)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rotatie, 0, 0, 1);
	glScalef(scalare->x, scalare->y, scalare->z);

	glColor4f(c.x, c.y, c.z, 1); //pentru ca avem si alpha
	glBegin(GL_LINES); //desenam limitele pt corpul fizic care vor delimita fizic de alt gen de obiecte din scena

		glVertex2i((int)-(size->x) / 2, (int)-(size->y) / 2); //colt stanga jos 0, 0 coord
		glVertex2i((int)size->x / 2, (int)-size->y / 2);
	
		glVertex2i((int)size->x / 2, (int)-size->y / 2); 
		glVertex2i((int)size->x / 2, (int)size->y / 2);

		glVertex2i((int)size->x / 2, (int)size->y / 2);
		glVertex2i((int)-size->x / 2, (int)size->y / 2);

		glVertex2i((int)-size->x / 2, (int)size->y / 2);
		glVertex2i((int)-(size->x) / 2, (int)-(size->y) / 2);


		glEnd();

}

void Rigid::Forta(Vector3p forta)
{
	acceleratie = acceleratie + forta;
}
