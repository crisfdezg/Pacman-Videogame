#pragma once
#define tam 25
#include "Esfera.h"
/*la clase lista esferas es una lista din�mica de esferas para el conjunto de esferas del pacman;en el constructor se le pasa por par�metro
una matriz global llamada laberinto que contiene 0 donde no hay cubos e 1 donde si lo hay,asi solo se inicializan las esferas
en caso de que no haya cubo,tambien tiene el metodo eliminar para eliminar dinamicamente las esferas cuando el usuario pase por alguna
de ellas.Como se puede apreciar,su �nico atributo es una matriz de punteros a objetos tipo esfera cada uno de los cuales apuntara a
una esferita.
 */
class Listaesferas
{
public:
	Listaesferas(int v[tam][tam]);
	~Listaesferas(void);   
	Esfera * lista[tam][tam];
			
	void Eliminar(int,int);

private:
	void Dibuja(int v[tam][tam]);
	int numero;
};


