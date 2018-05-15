#include "Cubo.h"
 
 
Cubo::Cubo()
{
}
 
 
Cubo::~Cubo()
{
}

void Cubo::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Cubo::SetLado(float l)
{
	if(l<0.1F)
	{
		l = 0.1F;
	}
	lado = l;
}
 
void Cubo::SetPos(float ix, float iy, float iz)
{
	posicion.x = ix;
	posicion.y = iy;
	posicion.z = iz;
}

void Cubo::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x+0.5, posicion.y+0.5, posicion.z);
	glutSolidCube(lado);
	glTranslatef(-posicion.x-0.5, -posicion.y-0.5, -posicion.z);
}