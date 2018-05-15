#pragma once
#include "glut.h"
#include "Vector3D.h"

/*La clase cubo servirá para crear el laberinto del pacman,lo que se ve como un laberinto no es mas que un conjunto de cubos dibujados con 
un determinado patrón;el cubo tiene lado, posicion(para la cual se usa la clase vector 3D que es simplemente un vector con las 3 coordenadas
de el cubo,y los metodos son para asignar color,lado,posicion,y para dibujarse*/

class Cubo
{
private:
    float lado;
    vector3D posicion;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
 
public:
    Cubo();
    ~Cubo();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    void SetLado(float l);
    void SetPos(float ix, float iy, float iz);
    void Dibuja();
};