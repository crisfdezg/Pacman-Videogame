#pragma comment(lib, "winmm.lib")
#include "glut.h"
#include "Esfera.h"
#include "Fantasma.h"
#include "Cubo.h"
#include "Vector3D.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#define tam 25
#include <new>
#include "Listaesferas.h"
#include "funciones.h"
#include "OpenGL.h"


void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnDraw0(void);
void OnDraw1(void);
void OnDraw2(void);
void OnDraw3(void);
void DibujarV(int columna, int filai, int filaf);
void DibujarH(int fila, int columnai, int columnaf);
float distancia(int a,int b,Esfera e,Listaesferas f);
void todo0(int a[tam][tam]);
void rotar(int c,float *q,float *w);

float x1=0.0f;
float y2=10.0f;
int laberinto[tam][tam]; 	//matriz que contendrá 0 o 1 en funcion de si hay cubo o no
int f;
int d=1;
int *p;
int *x2;
float t=0;
int timing=0;
int timing2=0;
int dib=1;
int varpri=0;
 
Esfera esfera; //Esfera principal:usuario
Cubo cubo[tam][tam];//matriz de cubos
Listaesferas bolitas(laberinto);//Lista de esferas llamada bolitas

//Fantasmas
Fantasma fantasma1;
Fantasma fantasma2;
Fantasma fantasma3;
Fantasma fantasma4;

int mainWindow, subWindow1, subWindow2;

void init()
{
	glEnable(GL_LIGHT0); 
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	glutTimerFunc(25, OnTimer, 0);//25 ms 
    glutKeyboardFunc(OnKeyboardDown);
}


int main(int argc, char* argv[])
{

	todo0(laberinto);
    //Inicializar el gestor de ventanas GLUT 
    //y crear la ventana 
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600); //por defecto (800,600)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    mainWindow = glutCreateWindow("Pacman");

	//Sonido de inicio
	PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_FILENAME |SND_ASYNC );
	
	// callbacks for main window
	//glutDisplayFunc();
	glutDisplayFunc(OnDraw0);
	init();


	// sub windows
	subWindow2 = glutCreateSubWindow(mainWindow, 1200-320,10,300, 300);
	glutDisplayFunc(OnDraw3);
	init();

	subWindow1 = glutCreateSubWindow(mainWindow, 0,0,1200, 600);
	glutDisplayFunc(OnDraw3);
	init();
	

	//se asigna atributos a los fantasmas y a la esfera
    esfera.SetColor(255, 255, 0); 
    esfera.SetRadio(0.1); 
    esfera.SetPos(12.5, 12.5, 0);

	fantasma1.SetColor(230,0,38);
	fantasma1.SetBas(0.25);
	fantasma1.SetHeight(1.5);
	fantasma1.SetPos(1.5,23.5,-1.0);

	fantasma2.SetColor(161,6,132);
	fantasma2.SetBas(0.25);
	fantasma2.SetHeight(1.5);
	fantasma2.SetPos(23.5,23.5,-1.0);

	fantasma3.SetColor(0,60,146);
	fantasma3.SetBas(0.25);
	fantasma3.SetHeight(1.5);
	fantasma3.SetPos(1.5 ,1.5,-1.0);

	fantasma4.SetColor(0,255,0);
	fantasma4.SetBas(0.25);
	fantasma4.SetHeight(1.5);
	fantasma4.SetPos(23.5 ,1.5,-1.0);

	//se crean los cubos 
    for (int i = 0; i < tam; i++)
	{
        for (int j = 0; j < tam; j++)
		{
			cubo[i][j].SetColor(233, 84, 0);
			cubo[i][j].SetLado(1);
			cubo[i][j].SetPos(i, j, 0);
		}
	}
	//se crean las esferas,se condiciona a que la lista de esferas(bolitas) no apunte a NULL porque en ese caso se habria eliminado dicha esfera
	for (int j=0; j<tam; j++)
	{
		for(int k=0; k<tam; k++)
		{
			if((laberinto[j][k]==0)||(bolitas.lista[j][k]!=NULL))
			{
                bolitas.lista[j][k]->SetRadio(0.1);
				bolitas.lista[j][k]->SetPos(j+0.5, k+0.5, 0);
			}
		}
	}
     

    //pasarle el control a GLUT,que llamara a los callbacks 
    glutMainLoop();
	
    return 0;
}

void OnDraw0(void)
{
	
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void OnDraw1(void)
{
	glutSetWindow(subWindow1);
	
	  
    //Borrado de la pantalla 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    //Para definir el punto de vista 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(esfera.Getposx(), esfera.Getposy(), 0.1, // posicion del ojo 
        esfera.Getposx()+x1, esfera.Getposy()+y2, 0.0, // hacia que punto mira (0,0,0) 
        0.0, 0.0, 1.0); // definimos hacia arriba (eje Z)
	

	//se dibujan los fantasmas y las esfera
    esfera.Dibuja();
	fantasma1.Dibuja();
	fantasma2.Dibuja();
	fantasma3.Dibuja();
	fantasma4.Dibuja();

	//se coloca un suelo
	glColor3ub(0,255,0); 
	glBegin(GL_POLYGON); 
	glVertex3f(0.0f,0.0f,-0.5f); 
	glVertex3f(0.0f,25.0f,-0.5f); 
	glVertex3f(25.0f,25.0f,-0.5f); 
	glVertex3f(25.0f,0.0f,-0.5f); 
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd(); 

 	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);
	glEnd(); 

   //Dibujamos la lista esferas (Solo si no apunta a NULL!!)
     for(int i=0;i<tam;i++)
	 {
		 for(int j=0;j<tam;j++)
		 {
			 if((bolitas.lista[i][j]!=NULL))
			 {
				 bolitas.lista[i][j]->Dibuja2();
			 }
		 }
	 }

	 bolitas.Eliminar(12,12);//eliminamos la bolita en la que se va a situar el pacman
   
    //Dibuja cuadrado exterior     
    DibujarV(0, 0, tam-1);
    DibujarV(tam-1, 0, tam-1);
    DibujarH(0,0,tam-1);
    DibujarH(tam-1,0,tam-1);
 
    //Dibuja elementos internos
    DibujarV(2,2,6);
    DibujarV(2,18,22);
    DibujarV(4,4,4);
    DibujarV(4,20,20);
    DibujarV(6,6,6);
    DibujarV(6,18,18);
    DibujarV(6,2,4);
    DibujarV(6,20,22);
    DibujarV(8,1,6);
    DibujarV(8,18,23);

	DibujarV(22,2,6);
    DibujarV(22,18,22);
    DibujarV(20,4,4);
    DibujarV(20,20,20);
    DibujarV(18,6,6);
    DibujarV(18,18,18);
    DibujarV(18,2,4);
    DibujarV(18,20,22);
    DibujarV(16,1,6);
    DibujarV(16,18,23);
 
    DibujarH(2,3,5);
	DibujarH(2,19,21);
    DibujarH(22,3,5);
	DibujarH(22,19,21);
    DibujarH(6,3,4);
	DibujarH(6,20,21);
    DibujarH(18,3,4);
	DibujarH(18,20,21);
    DibujarH(8,1,6);
	DibujarH(8,18,23);
    DibujarH(16,1,6);
	DibujarH(16,18,23);

    DibujarH(2,10,14);
    DibujarH(3,14,14);
    DibujarH(4,12,12);
    DibujarH(6,14,14);
    DibujarH(5,12,14);
    DibujarH(7,12,12);
    DibujarH(8,8,16);
	DibujarH(9,10,10);
	DibujarH(9,12,12);
	DibujarH(9,14,14);
	DibujarH(11,10,11);
	DibujarH(11,13,14);
	DibujarH(14,10,14);

	DibujarH(22,10,14);
    DibujarH(21,10,10);
    DibujarH(20,12,12);
    DibujarH(18,10,10);
    DibujarH(19,10,12);
    DibujarH(17,12,12);
    DibujarH(16,8,16);

	DibujarH(10,2,6);
	DibujarH(12,2,6);
	DibujarH(14,2,6);
	DibujarH(10,18,22);
	DibujarH(12,18,22);
	DibujarH(14,18,22);

	DibujarV(10,3,6);
    DibujarV(14,18,22);
    DibujarV(8,10,14);
	DibujarV(16,10,14);
    DibujarV(10,12,13);
    DibujarV(14,12,13);

	
	if(varpri==1)
	{
		OpenGL::Print("GAMEOVER",540,150,255,255,255);
		OpenGL::Print("PULSE -e- PARA SALIR",500,250,255,255,255);
	}
	

	
  
    //no borrar esta linea ni poner nada despues 
    glutSwapBuffers();
}

void OnDraw2(void)
{
	glutSetWindow(subWindow2);
	  
    //Borrado de la pantalla 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    //Para definir el punto de vista 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
	gluLookAt(12.5,10, 40, // posicion del ojo 
        12.5, 12.5, 0, // hacia que punto mira (0,0,0) 
        0.0, 0.0, 1.0); // definimos hacia arriba (eje Z)
	
	//se dibujan fantasmas y las esferas
    esfera.Dibuja();
	fantasma1.Dibuja();
	fantasma2.Dibuja();
	fantasma3.Dibuja();
	fantasma4.Dibuja();

	//se coloca el suelo
	glColor3ub(0,255,0); 
	glBegin(GL_POLYGON); 
	glVertex3f(0.0f,0.0f,-0.5f); 
	glVertex3f(0.0f,25.0f,-0.5f); 
	glVertex3f(25.0f,25.0f,-0.5f); 
	glVertex3f(25.0f,0.0f,-0.5f); 
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.0f, 0.0f, 0.0f);
	glEnd(); 

 	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 20.0f, 0.0f);
	glEnd(); 

   //Dibujamos la lista esferas
     for(int i=0;i<tam;i++)
	 {
		 for(int j=0;j<tam;j++)
		 {
			 if((bolitas.lista[i][j]!=NULL))
			 {
				 bolitas.lista[i][j]->Dibuja2();
			 }
		 }
	 }

	 bolitas.Eliminar(12,12); //eliminamos la bolita en la que se va a situar el pacman
   
    //Dibuja cuadrado exterior
    DibujarV(0, 0, tam-1);
    DibujarV(tam-1, 0, tam-1);
    DibujarH(0,0,tam-1);
    DibujarH(tam-1,0,tam-1);
 
    //Dibuja elementos internos
    DibujarV(2,2,6);
    DibujarV(2,18,22);
    DibujarV(4,4,4);
    DibujarV(4,20,20);
    DibujarV(6,6,6);
    DibujarV(6,18,18);
    DibujarV(6,2,4);
    DibujarV(6,20,22);
    DibujarV(8,1,6);
    DibujarV(8,18,23);

	DibujarV(22,2,6);
    DibujarV(22,18,22);
    DibujarV(20,4,4);
    DibujarV(20,20,20);
    DibujarV(18,6,6);
    DibujarV(18,18,18);
    DibujarV(18,2,4);
    DibujarV(18,20,22);
    DibujarV(16,1,6);
    DibujarV(16,18,23);
 
    DibujarH(2,3,5);
	DibujarH(2,19,21);
    DibujarH(22,3,5);
	DibujarH(22,19,21);
    DibujarH(6,3,4);
	DibujarH(6,20,21);
    DibujarH(18,3,4);
	DibujarH(18,20,21);
    DibujarH(8,1,6);
	DibujarH(8,18,23);
    DibujarH(16,1,6);
	DibujarH(16,18,23);

    DibujarH(2,10,14);
    DibujarH(3,14,14);
    DibujarH(4,12,12);
    DibujarH(6,14,14);
    DibujarH(5,12,14);
    DibujarH(7,12,12);
    DibujarH(8,8,16);
	DibujarH(9,10,10);
	DibujarH(9,12,12);
	DibujarH(9,14,14);
	DibujarH(11,10,11);
	DibujarH(11,13,14);
	DibujarH(14,10,14);

	DibujarH(22,10,14);
    DibujarH(21,10,10);
    DibujarH(20,12,12);
    DibujarH(18,10,10);
    DibujarH(19,10,12);
    DibujarH(17,12,12);
    DibujarH(16,8,16);

	DibujarH(10,2,6);
	DibujarH(12,2,6);
	DibujarH(14,2,6);
	DibujarH(10,18,22);
	DibujarH(12,18,22);
	DibujarH(14,18,22);

	DibujarV(10,3,6);
    DibujarV(14,18,22);
    DibujarV(8,10,14);
	DibujarV(16,10,14);
    DibujarV(10,12,13);
    DibujarV(14,12,13);


    //no borrar esta linea ni poner nada despues 
    glutSwapBuffers();
}

/*La funcion de este OnDraw es pasar de una ventana a otra para que 
sean ambas lo mas coordinadas posible*/
void OnDraw3(void)
{
	if(dib==0)
	{
		glutSetWindow(subWindow1);
		OnDraw1();
	}
	if(dib==1)
	{
		glutSetWindow(subWindow2);
		OnDraw2();
	}
}


 

void OnTimer(int value) 
{
	if(dib==0) dib=1;
	else if(dib==1) dib=0;
	
	if(timing==2292) 
	{
			timing=0;
			fantasma3.SetPos(1.5, 1.5, 0);
			fantasma2.SetPos(23.5, 23.5, 0);
	}

	if(timing2==2178) 
	{
			timing2=0;
			fantasma1.SetPos(1.5, 23.5, 0);
			fantasma4.SetPos(23.5, 1.5, 0);
	}

	int a=esfera.Getposx();
	int b=esfera.Getposy();

	glutTimerFunc(25,OnTimer,0);
	
	
	float dist=distancia(7,8,esfera,bolitas);
	t++;

	for (int j=0; j<tam; j++)//funion para el movimiento(MAS) de las esferitas
	{
		for(int k=0; k<tam; k++)
		{
			if((laberinto[j][k]==0)&&(bolitas.lista[j][k]!=NULL))
			{
				bolitas.lista[j][k]->Mueve(t);
			}
		}
	}

	//Logica de la eliminacion de esferas:Doble bucle for en el que si la distancia es menor que 0.5 se elimina la esfera
	for (int j=0; j<tam; j++)
	{
		for(int k=0; k<tam; k++)
		{
			if(bolitas.lista[j][k]!=NULL)
			{
				if(distancia(j,k,esfera,bolitas)<0.5f)
				{ 
					bolitas.Eliminar(j,k);
					//Sonido de eliminacion
					PlaySound(TEXT("pacman_crunch.wav"), NULL, SND_FILENAME |SND_ASYNC );
				}
			}
		}
	}
	
	glutPostRedisplay(); 

    //movimiento de los fantasmas en el que se les pasa el tiempo por parametro
	fantasma3.Mueve3(timing);
	fantasma2.Mueve2(timing);
	fantasma4.Mueve4(timing2);
	fantasma1.Mueve1(timing2);
	
	timing++;
	timing2++;

	float distanciasfantasmas[4]={distancia2(esfera, fantasma1), distancia2(esfera, fantasma2), distancia2(esfera, fantasma3), distancia2(esfera, fantasma4)};
	float timer=0;

	for(int i=0;i<4;i++)
	{
		if(distanciasfantasmas[i]<0.10)
		{
			varpri=1;
		}
	}
			
} 
 
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{ 
	// Tecla para salir del juego
	if(key=='e')
	{
		exit(0);	
	}

	
	 //Logica de la rotacion(explicada en el PDF)
	if(key=='k')
	{
		if(d<=4)
		{
			d++;
			rotar(d,&x1,&y2);
		}
		else
		{
			d=d%4;
			rotar(d,&x1,&y2);
		}
	}

	if(key=='j')
	{
		if(d==1)
		{
			d=4;
			rotar(d,&x1,&y2);
		}
		else
		{
			d--;
			rotar(d,&x1,&y2);
		}
	}
	
     
     int a=esfera.Getposx();
	 int b=esfera.Getposy();

	 int c1=esfera.Mayomenxizda();
	 int c2=esfera.Mayomenxdcha();
	 int c3=esfera.Mayomenyarriba();
	 int c4=esfera.Mayomenyabajo();

	 //Logica del movimiento(explicada en el PDF)
	 if(key=='w')
	 {
		 if (d==1)
		 {
			 if(laberinto[a][b+1]==0)
			 {
				 esfera.Avanzar();
			 }
			 if((laberinto[a][b+1]==1)&&(c4==1))
			 {
				esfera.Avanzar();
			 }
		 }
		 if(d==4)
		 {
			 if(laberinto[a-1][b]==0)
			 {
				 esfera.Izquierda();
			 }
			 if((laberinto[a-1][b]==1)&&(c1==1))
			 {
				 esfera.Izquierda();
			 }
		 }
		 if (d==2)
		 {
			 if(laberinto[a+1][b]==0)
			 {
				 esfera.Derecha();
			 }
			 if((laberinto[a+1][b]==1)&&c2==1)
			 {
				esfera.Derecha();
			 }
		 }
		 if (d==3)
		 {
			 {
				 if(laberinto[a][b-1]==0)
				 {
					 esfera.Retroceder();
				 }
				 if((laberinto[a][b-1]==1)&&(c3==1))
				 {
					 esfera.Retroceder();
				 }
			 }
		 }
	 }

	 if(key=='a')
	 {
		 if (d==1)
		 { 
			 if(laberinto[a-1][b]==0)
			 {
				 esfera.Izquierda();
			 }
			 if((laberinto[a-1][b]==1)&&(c1==1))
			 {
				 esfera.Izquierda();
			 }
		 }
		 if (d==2)
		 { 
			 if(laberinto[a][b+1]==0)
			 {
				 esfera.Avanzar();
			 }
			 if((laberinto[a][b+1]==1)&&(c4==1))
			 {
				 esfera.Avanzar();
			 }
		 }
		 if (d==3)
		 {
			 if(laberinto[a+1][b]==0)
			 {
				 esfera.Derecha();
			 }
			 if((laberinto[a+1][b]==1)&&c2==1)
			 {
				 esfera.Derecha();
			 }
		 }
		 if (d==4)
		 {
			 if(laberinto[a][b-1]==0)
			 {
				 esfera.Retroceder();
			 }
			 if((laberinto[a][b-1]==1)&&(c3==1))
			 {
				 esfera.Retroceder();
			 }
		 }
	 }
	 
	 if(key=='d')
	 {
		 if (d==1)
		 { 
			 if(laberinto[a+1][b]==0)
			 {
				 esfera.Derecha();
			 }
			 if((laberinto[a+1][b]==1)&&c2==1)
			 {
				 esfera.Derecha();
			 }
		 }
		 if (d==2)	
		 {
			 if(laberinto[a][b-1]==0)
			 {
				 esfera.Retroceder();
			 }
			 if((laberinto[a][b-1]==1)&&(c3==1))
			 {
				 esfera.Retroceder();
			 }
		 }
		 if (d==3)
		 { 
			 if(laberinto[a-1][b]==0)
			 {
				 esfera.Izquierda();
			 }
			 if((laberinto[a-1][b]==1)&&(c1==1))
			 {
				 esfera.Izquierda();
			 }
		 }
		 if (d==4)
		 { 
			 if(laberinto[a][b+1]==0)
			 {
				 esfera.Avanzar();
			 }
			 if((laberinto[a][b+1]==1)&&(c4==1))
			 {
				 esfera.Avanzar();
			 }
		 }
	 }
	            
    if(key=='s')
	{
		if (d==1)
		{
			if(laberinto[a][b-1]==0)
			{
				esfera.Retroceder();
			}
			if((laberinto[a][b-1]==1)&&(c3==1))
			{
				esfera.Retroceder();
			}
		}
		if (d==2)
		{
			if(laberinto[a-1][b]==0)
			{
				esfera.Izquierda();
			}
			if((laberinto[a-1][b]==1)&&(c1==1))
			{
				esfera.Izquierda();
			}
		}
		if (d==3)
		{
			if(laberinto[a][b+1]==0)
			{
				esfera.Avanzar();
			}
			if((laberinto[a][b+1]==1)&&(c4==1))
			{
				esfera.Avanzar();
			}
		}
		if (d==4)
		{
			if(laberinto[a+1][b]==0)
			{
				esfera.Derecha();
			}
			if((laberinto[a+1][b]==1)&&c2==1)
			{
				esfera.Derecha();
			}
		}
	}
	
	glutPostRedisplay();
}

   /*Las funciones dibujar H y dibujar V son para dibujar una fila o columna de cubos, 
   se le pasa la posicoin inicial(i) y final(f) y el patron es simplemente un for;
   en ellas se asigna el valor de 1 a la matriz  laberinto que va perfectamente sincronizada
   con los cubos(y con la lista de esferas) en el sentido de que se 'superpone' la información*/ 

void DibujarH(int fila, int columnai, int columnaf)
{
    for(int i=columnai; i<=columnaf; i++)
    {
        cubo[i][fila].Dibuja();
        laberinto[i][fila]=1;
    }
}
 
void DibujarV(int columna, int filai, int filaf)
{
    for(int i=filai; i<=filaf; i++)
    {
        cubo[columna][i].Dibuja();
        laberinto[columna][i]=1;
    }
}
