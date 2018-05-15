#include "Fantasma.h"
#include <math.h>
void Fantasma::SetColor(unsigned char r,unsigned char v,unsigned char a) 
{ 
    rojo=r;
    verde=v; 
    azul=a; 
} 
 
void Fantasma::SetBas(float r) 
{ 
    if(r<0.1F)
        r=0.1F; 
    bas=r; 
}

void Fantasma::SetHeight(float h) 
{ 
    if(h<0.1F)
        h=0.1F; 
    height=h; 
} 
 
int Fantasma::GetBas()
{
    return bas;
}
 
void Fantasma::SetPos(float ix,float iy,float iz) 
{ 
    posicion.x=ix;
    posicion.y=iy;
    posicion.z=iz; 
} 
 
void Fantasma::Dibuja() 
{ 
    glColor3ub(rojo,verde,azul);
    glTranslatef(posicion.x,posicion.y,posicion.z);  
    glutSolidCone(bas,height,15,15);
    glTranslatef(-posicion.x,-posicion.y,-posicion.z); 
} 


float Fantasma::Getposx()
{
	return posicion.x;
}
float Fantasma::Getposy()
{
	return posicion.y;
}
void Fantasma::Mueve3 (float timing)
{
		if(timing<172)
		{
			posicion.x +=0.035;
		}
	    else if(timing<401)
		{
			posicion.y+=0.035;
		}
		else if(timing<573)
		{
			posicion.x-=0.035;
		}
		else if(timing<630)
		{
			posicion.y+=0.035;
		}
		else if(timing<802)
		{
			posicion.x+=0.035;
		}
		else if(timing<860)
		{
			posicion.y+=0.035;
		}
		else if(timing<1032)
		{
			posicion.x-=0.035;
		}
		else if(timing<1089)
		{
			posicion.y+=0.035;
		}
		else if(timing<1318)
		{
			posicion.x+=0.035;
		}
		else if(timing<1490)
		{
			posicion.y-=0.035;
		}
		else if(timing<1547)
		{
			posicion.x-=0.035;
		}
		else if(timing<1662)
		{
			posicion.y-=0.035;
		}
		else if(timing<1720)
		{
			posicion.x-=0.035;
		}
		else if(timing<1777)
		{
			posicion.y-=0.035;
		}
		else if(timing<1834)
		{
			posicion.x-=0.035;
		}
		else if(timing<1892)
		{
			posicion.y+=0.035;
		}
		else if(timing<1949)
		{
			posicion.x+=0.035;
		}
		else if(timing<2006)
		{
			posicion.y+=0.035;
		}
		else if(timing<2121)
		{
			posicion.x-=0.035;
		}
		else if(timing<2292)
		{
			posicion.y-=0.035;
		}
}

void Fantasma::Mueve2 (float timing)
{
		if(timing<172)
		{
			posicion.x-=0.035;
		}
	    else if(timing<401)
		{
			posicion.y-=0.035;
		}
		else if(timing<573)
		{
			posicion.x+=0.035;
		}
		else if(timing<630)
		{
			posicion.y-=0.035;
		}
		else if(timing<802)
		{
			posicion.x-=0.035;
		}
		else if(timing<860)
		{
			posicion.y-=0.035;
		}
		else if(timing<1032)
		{
			posicion.x+=0.035;
		}
		else if(timing<1089)
		{
			posicion.y-=0.035;
		}
		else if(timing<1318)
		{
			posicion.x-=0.035;
		}
		else if(timing<1490)
		{
			posicion.y+=0.035;
		}
		else if(timing<1547)
		{
			posicion.x+=0.035;
		}
		else if(timing<1662)
		{
			posicion.y+=0.035;
		}
		else if(timing<1720)
		{
			posicion.x+=0.035;
		}
		else if(timing<1777)
		{
			posicion.y+=0.035;
		}
		else if(timing<1834)
		{
			posicion.x+=0.035;
		}
		else if(timing<1892)
		{
			posicion.y-=0.035;
		}
		else if(timing<1949)
		{
			posicion.x-=0.035;
		}
		else if(timing<2006)
		{
			posicion.y-=0.035;
		}
		else if(timing<2121)
		{
			posicion.x+=0.035;
		}
		else if(timing<2292)
		{
			posicion.y+=0.035;
		}
}

void Fantasma::Mueve4 (float timing)
{
		if(timing<172)
		{
			posicion.x-=0.035;
		}
	    else if(timing<344)
		{
			posicion.y+=0.035;
		}
		else if(timing<459)
		{
			posicion.x-=0.035;
		}
		else if(timing<487)
		{
			posicion.y-=0.035;
		}
		else if(timing<545)
		{
			posicion.x-=0.035;
		}
		else if(timing<630)
		{
			posicion.y-=0.035;
		}
		else if(timing<688)
		{
			posicion.x+=0.035;
		}
		else if(timing<716)
		{
			posicion.y+=0.035;
		}
		else if(timing<774)
		{
			posicion.x+=0.035;
		}
		else if(timing<860)
		{
			posicion.y-=0.035;
		}
		else if(timing<1032)
		{
			posicion.x-=0.035;
		}
		else if(timing<1204)
		{
			posicion.y+=0.035;
		}
		else if(timing<1261)
		{
			posicion.x+=0.035;
		}
		else if(timing<1290)
		{
			posicion.y-=0.035;
		}
		else if(timing<1347)
		{
			posicion.x+=0.035;
		}
		else if(timing<1376)
		{
			posicion.y+=0.035;
		}
		else if(timing<1491)
		{
			posicion.x+=0.035;
		}
		else if(timing<1548)
		{
			posicion.y-=0.035;
		}
		else if(timing<1605)
		{
			posicion.x+=0.035;
		}
		else if(timing<1662)
		{
			posicion.y-=0.035;
		}
		else if(timing<1720)
		{
			posicion.x+=0.035;
		}
		else if(timing<1777)
		{
			posicion.y+=0.035;
		}
		else if(timing<1834)
		{
			posicion.x-=0.035;
		}
		else if(timing<1892)
		{
			posicion.y+=0.035;
		}
		else if(timing<2007)
		{
			posicion.x+=0.035;
		}
		else if(timing<2178)
		{
			posicion.y-=0.035;
		}
}

void Fantasma::Mueve1 (float timing)
{
		if(timing<172)
		{
			posicion.x+=0.035;
		}
	    else if(timing<344)
		{
			posicion.y-=0.035;
		}
		else if(timing<459)
		{
			posicion.x+=0.035;
		}
		else if(timing<487)
		{
			posicion.y+=0.035;
		}
		else if(timing<545)
		{
			posicion.x+=0.035;
		}
		else if(timing<630)
		{
			posicion.y+=0.035;
		}
		else if(timing<688)
		{
			posicion.x-=0.035;
		}
		else if(timing<716)
		{
			posicion.y-=0.035;
		}
		else if(timing<774)
		{
			posicion.x-=0.035;
		}
		else if(timing<860)
		{
			posicion.y+=0.035;
		}
		else if(timing<1032)
		{
			posicion.x+=0.035;
		}
		else if(timing<1204)
		{
			posicion.y-=0.035;
		}
		else if(timing<1261)
		{
			posicion.x-=0.035;
		}
		else if(timing<1290)
		{
			posicion.y+=0.035;
		}
		else if(timing<1347)
		{
			posicion.x-=0.035;
		}
		else if(timing<1376)
		{
			posicion.y-=0.035;
		}
		else if(timing<1491)
		{
			posicion.x-=0.035;
		}
		else if(timing<1548)
		{
			posicion.y+=0.035;
		}
		else if(timing<1605)
		{
			posicion.x-=0.035;
		}
		else if(timing<1662)
		{
			posicion.y+=0.035;
		}
		else if(timing<1720)
		{
			posicion.x-=0.035;
		}
		else if(timing<1777)
		{
			posicion.y-=0.035;
		}
		else if(timing<1834)
		{
			posicion.x+=0.035;
		}
		else if(timing<1892)
		{
			posicion.y-=0.035;
		}
		else if(timing<2007)
		{
			posicion.x-=0.035;
		}
		else if(timing<2178)
		{
			posicion.y+=0.035;
		}
}
 
