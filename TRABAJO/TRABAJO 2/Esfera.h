#pragma once
#include "glut.h"
#include "Vector3D.h"
 /*La clase esfera servir� para hacer todas las bolas que se deber�n ir comiendo en el juego,y para el objeto del
 usuario que ser� tambi�n un objeto tipo esfera.Los atributos de la clase esfera son triviales y no merece la pena comentarlos,
 en cuanto a los metodos algunos de ellos  si que son menos intuitivos:la funcion mueve es simplemente para que las esferas del pacman se muevan para a�adir animaci�n al videojuego(hacen
 un movimento armonico simple en la que su posicion sigue un sen(wt);tambi�n contiene los metodos para moverse;hay 2 m�todos dibuja ya que 
 las esferas del pacman no son iguales que la esfera pricipal,las funciones mayomendcha e izda se comentar�n cuando aparezcan(b�sicamente son para 
 la l�gica del movimiento)*/
 
 
class Esfera 
{ 
	
private:
     
    float radio; 
    vector3D posicion;
    unsigned char rojo; 
    unsigned char verde; 
    unsigned char azul; 
 
    //tras los atributos, escribimos nuestros m�todos
public:
 
    void SetColor( unsigned char r,unsigned char v, unsigned char a);
    void SetRadio(float r); 
    void SetPos(float ix,float iy,float iz);
    void Dibuja(); 
    void Mueve(float time);
    void Avanzar();
    void Retroceder();
    void Derecha();
    void Izquierda();
    int GetRadio();
	float Getposx();
	float Getposy();
	int Mayomenxizda();
	int Mayomenxdcha();
	int Mayomenyarriba();
	int Mayomenyabajo();
	void Rotar();
	void Dibuja2();
	
	friend class Listaesferas; 
};