#include "Esfera.h"
#include <math.h>

void Esfera::SetColor(unsigned char r,unsigned char v,unsigned char a) 
{ 
    rojo=r;
    verde=v; 
    azul=a; 
} 
 
void Esfera::SetRadio(float r) 
{ 
    if(r<0.1F)
	{
		r=0.1F;
	}
    radio=r; 
} 
 
int Esfera::GetRadio()
{
    return radio;
}
 
void Esfera::SetPos(float ix,float iy,float iz) 
{ 
    posicion.x=ix;
    posicion.y = iy;
    posicion.z=iz; 
} 
 
void Esfera::Dibuja() 
{ 
    glColor3ub(rojo,verde,azul);
    glTranslatef(posicion.x,posicion.y,posicion.z);  
    glutSolidSphere(radio,20,20);
    glTranslatef(-posicion.x,-posicion.y,-posicion.z); 
} 

void Esfera::Dibuja2() 
{ 
    glColor3ub(245,222,179);
    glTranslatef(posicion.x,posicion.y,posicion.z);  
    glutSolidSphere(radio,20,20);
    glTranslatef(-posicion.x,-posicion.y,-posicion.z); 
} 
 
void Esfera::Mueve(float time) 
{
	posicion.z=0.1f*sin(0.02*time);
}
 
void Esfera::Avanzar()
{
    posicion.y += 0.0900001f;
}
 
void Esfera::Retroceder()
{
    posicion.y -= 0.09f;
}
 
void Esfera::Derecha()
{
    posicion.x += 0.090000001f;
}
 
void Esfera::Izquierda()
{
    posicion.x -= 0.09000000000001f;
}
 

float Esfera::Getposx()
{
	return posicion.x;
}

float Esfera::Getposy()
{
	return posicion.y;
}

int Esfera::Mayomenxizda()
{
	int w1=posicion.x;
	float w2=w1+0.1000001f;
	
	if(posicion.x>w2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Esfera::Mayomenxdcha()
{
	int w1=posicion.x;
	float w2=w1+0.89000001f;
	
	if(posicion.x<w2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Esfera::Mayomenyarriba()
{
	int s1=posicion.y;
	float s2=s1+0.1000001f;
	
	if(posicion.y>s2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Esfera::Mayomenyabajo()
{
	int s1=posicion.y;
	float s2=s1+0.89000001;
	
	if(posicion.y<s2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Esfera::Rotar()
{
	glPushMatrix();
	glRotatef(30,0,0,1);
	glPopMatrix();
}
