#pragma once
#include "glut.h"
#include "Vector3D.h"
 
 /* La clase fantasma servirá evidentemente para los fantasmas,conviene comentar las funciones mueve que sirven para el movimiento 
 de los fantasmas a lo largo del laberinto,basicamente se le pasa un parametro en el ontimer que mide de manera
 discreta el tiempo y con ese tiempo se contruye el algoritmo del movimiento de cada fantasma */

 
class Fantasma 
{ 
	
private:
     
    float bas;
	float height;
    vector3D posicion;
    unsigned char rojo; 
    unsigned char verde; 
    unsigned char azul; 
 
    //tras los atributos, escribimos nuestros métodos
public:
 
    void SetColor( unsigned char r,unsigned char v, unsigned char a);
    void SetBas(float r); 
	void SetHeight(float h);
    void SetPos(float ix,float iy,float iz);
	int GetBas();
	float Getposx();
	float Getposy();
    void Dibuja(); 
    void Mueve3(float time);
	void Mueve2(float time);
	void Mueve4(float time);
	void Mueve1(float time);
};