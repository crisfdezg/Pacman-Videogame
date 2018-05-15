#pragma once
#include "glut.h"
#include "Vector3D.h"
 /*La clase esfera servirá para hacer todas las bolas que se deberán ir comiendo en el juego,y para el objeto del
 usuario que será también un objeto tipo esfera.Los atributos de la clase esfera son triviales y no merece la pena comentarlos,
 en cuanto a los metodos algunos de ellos  si que son menos intuitivos:la funcion mueve es simplemente para que las esferas del pacman se muevan para añadir animación al videojuego(hacen
 un movimento armonico simple en la que su posicion sigue un sen(wt);también contiene los metodos para moverse;hay 2 métodos dibuja ya que 
 las esferas del pacman no son iguales que la esfera pricipal,las funciones mayomendcha e izda se comentarán cuando aparezcan(básicamente son para 
 la lógica del movimiento)*/
 
 
class Esfera 
{ 
	
private:
     
    float radio; 
    vector3D posicion;
    unsigned char rojo; 
    unsigned char verde; 
    unsigned char azul; 
 
    //tras los atributos, escribimos nuestros métodos
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