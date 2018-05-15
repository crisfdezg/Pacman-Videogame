#include "Listaesferas.h"
#include <stdio.h>
 
Listaesferas::Listaesferas(int v[tam][tam])
{
	for(int i=0;i<tam;i++)
	{
		for(int j=0;j<tam;j++)
		{
			if(v[i][j]==0)
			{
				lista[i][j]=new Esfera;
			}
			else{lista[i][j]=NULL;
			}
		}
	}
}

Listaesferas::~Listaesferas(void)
{
}

void Listaesferas::Dibuja(int v[tam][tam])
{
	for(int i=0;i<tam;i++)
	{
		for(int j=0;j<tam;j++)
		{
			if((v[i][j]==0)&&(lista[i][j]!=NULL))
			{
				lista[i][j]->Dibuja2();
			}
		}
	}
}

void Listaesferas::Eliminar(int i1,int i2)
{
	if(!(i1==7 && i2==8))
	{
		delete(lista[i1][i2]);
		lista[i1][i2]=NULL;
	}
}
