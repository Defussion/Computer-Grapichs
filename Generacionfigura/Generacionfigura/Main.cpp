#ifdef _WIN32


#include <iostream>
#include "glut.h"
#include "Vertex.h"

#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
using namespace std;


GLfloat cop_x = 15.0;
GLfloat cop_y = 15.0;
GLfloat cop_z = 15.0;
GLfloat Mx[16];
GLfloat Mp[16];

Vertex3D listaP[100];
Vertex3D listaQ[100];


void Translate(Vertex3D entrada[], Vertex3D out[], float tx, float ty, float tz, int Nvert) {
	for (int i = 0; i < Nvert; i++)
	{
		out[i].Setx(entrada[i].Getx() + tx);
		out[i].Sety(entrada[i].Gety() + ty);
		out[i].Setz(entrada[i].Getz() + tz);
	}
}

int M;
void IncializarPoligono() {
	listaP[0] = Vertex3D(-3, -5, 4);
	listaP[1] = Vertex3D(3, -5, 4);
	listaP[2] = Vertex3D(5, -5, 0);
	listaP[3] = Vertex3D(3, -5, -4);
	listaP[4] = Vertex3D(-3, -5, -4);
	listaP[5] = Vertex3D(-5, -5, 0);
    M = 6;
}














//Funcion de inicializacion
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	Mx[0] = -0.70711;
	Mx[1] = 0;
	Mx[2] = -0.70711;
	Mx[3] = -10;
	Mx[4] = -0.35630;
	Mx[5] = 0.86377;
	Mx[6] = -0.35630;
	Mx[7] = -8,25000;
	Mx[8] = -0.61078;
	Mx[9] = 0.50389;
	Mx[10] = 0.61078;
	Mx[11] = -10;
	Mx[12] = 0;
	Mx[13] = 0;
	Mx[14] = 0;
	Mx[15] = 1;

	Mp[0] = 1 / tan(1.0472);
	Mp[1] = 0;
	Mp[2] = 0;
	Mp[3] = 0;
	Mp[4] = 0;
	Mp[5] = 1 / tan(1.0472);
	Mp[6] = 0;
	Mp[7] = 0;
	Mp[8] = 0;
	Mp[9] = 0;
	Mp[10] = -301 / 299;
	Mp[11] = -1;
	Mp[12] = 0;
	Mp[13] = 0;
	Mp[14] = -601 / 299;
	Mp[15] = 0;

}
void DibujarPoligono() {
	IncializarPoligono();
	glBegin(GL_LINE_LOOP);
	for (int j = M - 1; j >= 0; j--)
	{
		glVertex3f(listaP[j].Getx(), listaP[j].Gety(), listaP[0].Getz());
		glEnd();
		for (int j = 0; j < 7; j++)
		{
			Translate(listaP, listaQ, 0, 2, 0, 6);
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[0].Getx(), listaP[0].Gety(), listaP[0].Getz());
			glVertex3f(listaP[1].Getx(), listaP[1].Gety(), listaP[1].Getz());
			glVertex3f(listaQ[1].Getx(), listaQ[1].Gety(), listaQ[1].Getz());
			glVertex3f(listaQ[0].Getx(), listaQ[0].Gety(), listaQ[0].Getz());
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[1].Getx(), listaP[1].Gety(), listaP[1].Getz());
			glVertex3f(listaP[2].Getx(), listaP[2].Gety(), listaP[2].Getz());
			glVertex3f(listaQ[2].Getx(), listaQ[2].Gety(), listaQ[2].Getz());
			glVertex3f(listaQ[1].Getx(), listaQ[1].Gety(), listaQ[1].Getz());
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[2].Getx(), listaP[2].Gety(), listaP[2].Getz());
			glVertex3f(listaP[3].Getx(), listaP[3].Gety(), listaP[3].Getz());
			glVertex3f(listaQ[3].Getx(), listaQ[3].Gety(), listaQ[3].Getz());
			glVertex3f(listaQ[2].Getx(), listaQ[2].Gety(), listaQ[2].Getz());
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[3].Getx(), listaP[3].Gety(), listaP[3].Getz());
			glVertex3f(listaP[4].Getx(), listaP[4].Gety(), listaP[4].Getz());
			glVertex3f(listaQ[4].Getx(), listaQ[4].Gety(), listaQ[4].Getz());
			glVertex3f(listaQ[3].Getx(), listaQ[3].Gety(), listaQ[3].Getz());
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[4].Getx(), listaP[4].Gety(), listaP[4].Getz());
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaQ[5].Getx(), listaQ[5].Gety(), listaQ[5].Getz());
			glVertex3f(listaQ[4].Getx(), listaQ[4].Gety(), listaQ[4].Getz());
			glEnd();
			glBegin(GL_LINE_LOOP);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[6].Getx(), listaP[6].Gety(), listaP[6].Getz());
			glVertex3f(listaQ[6].Getx(), listaQ[6].Gety(), listaQ[6].Getz());
			glVertex3f(listaQ[5].Getx(), listaQ[5].Gety(), listaQ[5].Getz());
			glEnd();

		}
		
	}
	for (int i = 0; i < M; i++)
	{ 
		listaP[i] = listaQ[i];

	}
	glBegin(GL_LINE_LOOP);
	for (int j = 0; j < M; j++)
	{
		glVertex3f(listaP[j].Getx(), listaP[j].Gety(), listaP[0].Getz());
		glEnd();
	}

}


//Para configurar la transformación de vista
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	//Punto de la camara, centro de vista, vector hacia arriba
	//gluLookAt(cop_x, cop_y, cop_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLoadMatrixf(Mx);

	// Transformaciones de modelado
	 /*glScalef (1.0, 2.0, 1.0);
	 glRotatef (30, 0.0, 0.0, 1.0);*/
	// Dibujar la geometria de los objetos de la escena
	/*glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	glEnd();
	glFlush();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 1, 1);
	glEnd();
	glFlush();
*/

	DibujarPoligono();
	glFlush();

}
//Configura la transformación de proyeccion para cambios en la dimension de la ventana
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);*/
	gluPerspective(60.0, (float)w / (float)h, 1.0, 300.0);
	/*glLoadMatrixf(Mp);*/
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
