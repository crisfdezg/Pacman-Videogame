/*La funcion distancia retorna la distancia entre una esfera e,y una esfera de la 
lista de esferas,servirá para la lógica de la eliminación:cuando la distancia entre estos
2 elemenos sea menor que la suma de sus radios se deberá eliminar esa esfera concreta(ver en el main)
La funcion distancia 2 es análoga pero entre esfera y fantasma, servirá para gestionar la 
intersecciñon esfera(usuario)-fantasma,cuando esta sea menor que la suma de radios significará
que el fantasma en concreto está demasiado cerca y finalizará el juego(GAME OVER!!)*/

float distancia(int a,int b,Esfera e,Listaesferas f)
{
	float distx= (f.lista[a][b]->Getposx()-e.Getposx());
	float disty= (f.lista[a][b]->Getposy()-e.Getposy());
	
	return sqrt(distx*distx+disty*disty);
}

float distancia2(Esfera e, Fantasma f)
{
	return sqrt((f.Getposx()-e.Getposx())*(f.Getposx()-e.Getposx())+(f.Getposy()-e.Getposy())*(f.Getposy()-e.Getposy()));
}

// La funcion todo0 inicializa una matriz que se le pase por parametros a 0
void todo0(int a[tam][tam])
{
	int i,j;
	
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			a[i][j]=0;
		}
	}
}
// La funcion rotar sirve para ir cambiando el punto de vista del juego,se explicará con mas detalle en el PDF
void rotar(int c,float *q,float *w)
{
	if(c==1)
	{
		*q=0.0f;
		*w=2.0f;
	}
	if(c==2)
	{
		*q=2.0f;
		*w=0.0f;
	}
	if(c==3)
	{
		*q=0.0f;
		*w=-2.0f;
	}
	if(c==4)
	{
		*q=-2.0f;
		*w=0.0f;
	}
}

