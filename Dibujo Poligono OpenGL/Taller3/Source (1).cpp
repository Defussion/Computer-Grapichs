//1er punto y 2 punto 
//1er punto y 2 punto 
#ifdef _WIN32
#include <iostream>;
#include "Header.h"
#include "glut.h"
#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

GLfloat cop_x = 10.0;
GLfloat cop_y = 8.25;
GLfloat cop_z = 10.0;
GLfloat Mx[16];
GLfloat Mp[16];
GLfloat Mo[16];
float pi = 3.1416;

Vertex3D listaB[100];
Vertex3D listaA[100];
Vertex3D listaP[100];
Vertex3D listaQ[100];
GLfloat colores[6][3];
GLfloat vertice[8][3];
GLint caras[6][4] = {
{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };


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
	listaP[0] = Vertex3D(-1, 0, 3);
	listaP[1] = Vertex3D(-1, 0, 1);
	listaP[2] = Vertex3D(-3, 0, 0);
	listaP[3] = Vertex3D(-4, 0, 2);
	listaP[4] = Vertex3D(-3, 0, 4);
	listaP[5] = Vertex3D(-2, -2,-4);
	M = 6;
}
void DibujarPiramide() {
	IncializarPoligono();
	glBegin(GL_LINE_LOOP);
	for (int j = M - 1; j >= 0; j--)
	{
		glVertex3f(listaP[j].Getx(), listaP[j].Gety(), listaP[j].Getz());

		glEnd();

		for (int j = 0; j < 7; j++)
		{
			Translate(listaP, listaQ, 0, 2, 0, 6);

			//glBegin(GL_POLYGON);
			//glColor3f(colores[j].Getx(),colores[j].Gety(),colores[j].Getz());
			//glColor3f(1, 1, 1);
			glVertex3f(listaP[0].Getx(), listaP[0].Gety(), listaP[0].Getz());
			glVertex3f(listaP[1].Getx(), listaP[1].Gety(), listaP[1].Getz());
			glVertex3f(listaP[2].Getx(), listaP[2].Gety(), listaP[2].Getz());
			glVertex3f(listaP[3].Getx(), listaP[3].Gety(), listaP[3].Getz());
			glVertex3f(listaP[4].Getx(), listaP[4].Gety(), listaP[4].Getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[0].Getx(), listaP[0].Gety(), listaP[0].Getz());
			glVertex3f(listaP[1].Getx(), listaP[1].Gety(), listaP[1].Getz());
			glEnd();

			glBegin(GL_TRIANGLES);
			glColor3f(0, 1, 0);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[1].Getx(), listaP[1].Gety(), listaP[1].Getz());
			glVertex3f(listaP[2].Getx(), listaP[2].Gety(), listaP[2].Getz());

			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(0, 1, 1);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[2].Getx(), listaP[2].Gety(), listaP[2].Getz());
			glVertex3f(listaP[3].Getx(), listaP[3].Gety(), listaP[3].Getz());
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 1);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[3].Getx(), listaP[3].Gety(), listaP[3].Getz());
			glVertex3f(listaP[4].Getx(), listaP[4].Gety(), listaP[4].Getz());
			glEnd();
			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 1);
			glVertex3f(listaP[5].Getx(), listaP[5].Gety(), listaP[5].Getz());
			glVertex3f(listaP[4].Getx(), listaP[4].Gety(), listaP[4].Getz());
			glVertex3f(listaP[0].Getx(), listaP[0].Gety(), listaP[0].Getz());
			glEnd();
		}
		
	}
	for (int i = 0; i < M; i++)
	{
		listaP[i] = listaQ[i];

	}
	/*glBegin(GL_LINE_LOOP);
	for (int j = 0; j < M; j++)
	{
		glVertex3f(listaP[j].Getx(), listaP[j].Gety(), listaP[0].Getz());
		glEnd();
	}*/

}

//Funcion de inicializacion
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	Mx[0] = 0.71;
	Mx[1] = -0.36;
	Mx[2] = 0.61;
	Mx[3] = 0;

	Mx[4] = 0;
	Mx[5] = -0.86;
	Mx[6] = 0.50;
	Mx[7] = 0;

	Mx[8] = -0.71;
	Mx[9] = -0.36;
	Mx[10] = 0.61;
	Mx[11] = 0;

	Mx[12] = 0;
	Mx[13] = 0;
	Mx[14] = -10;
	Mx[15] = 1;
	glLoadMatrixf(Mx);

	Mp[0] = tan(pi / 6);
	Mp[1] = 0;
	Mp[2] = 0;
	Mp[3] = 0;

	Mp[4] = 0;
	Mp[5] = tan(pi / 6);
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
	glLoadMatrixf(Mp);

	Mo[0] = 0.1538f;
	Mo[1] = 0;
	Mo[2] = 0;
	Mo[3] = 0;

	Mo[4] = 0;
	Mo[5] = 0.1538f;
	Mo[6] = 0;
	Mo[7] = 0;

	Mo[8] = 0;
	Mo[9] = 0;
	Mo[10] = -0.0067f;
	Mo[11] = -1;

	Mo[12] = -1;
	Mo[13] = -1;
	Mo[14] = -(301 / 299);
	Mo[15] = 1;
	glLoadMatrixf(Mo); //Matriz ortografica
	vertice[0][0] = 0; vertice[0][1] = 0; vertice[0][2] = 0;
	vertice[1][0] = 3.25;  vertice[1][1] = 0; vertice[1][2] = 0;
	vertice[2][0] = 3.25;  vertice[2][1] = 0; vertice[2][2] = 1;
	vertice[3][0] = 0;  vertice[3][1] = 0; vertice[3][2] = 1;


	vertice[4][0] = 0;  vertice[4][1] = 1; vertice[4][2] = 0;
	vertice[5][0] = 3.25;  vertice[5][1] = 1; vertice[5][2] = 0;
	vertice[6][0] = 3.25;  vertice[6][1] = 1; vertice[6][2] = 1;
	vertice[7][0] = 0;  vertice[7][1] = 1; vertice[7][2] = 1;


	colores[0][0] = 1; colores[0][1] = 0; colores[0][2] = 0;
	colores[1][0] = 0; colores[1][1] = 1; colores[1][2] = 0;
	colores[2][0] = 0; colores[2][1] = 0; colores[2][2] = 1;
	colores[3][0] = 0; colores[3][1] = 1; colores[3][2] = 1;
	colores[4][0] = 1; colores[4][1] = 1; colores[4][2] = 0;
	colores[5][0] = 1; colores[5][1] = 0; colores[5][2] = 1;

	glEnable(GL_DEPTH_TEST);

}
void dibujarcara(void)
{
	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(colores[i][0], colores[i][1], colores[i][2]);

		glVertex3f(vertice[caras[i][0]][0], vertice[caras[i][0]][1], vertice[caras[i][0]][2]);
		glVertex3f(vertice[caras[i][1]][0], vertice[caras[i][1]][1], vertice[caras[i][1]][2]);
		glVertex3f(vertice[caras[i][2]][0], vertice[caras[i][2]][1], vertice[caras[i][2]][2]);
		glVertex3f(vertice[caras[i][3]][0], vertice[caras[i][3]][1], vertice[caras[i][3]][2]);

		glEnd();
	}


}

void dibujarvertices(void) {

	for (int j = 0; j < 8; j++)
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(vertice[j][0], vertice[j][1], vertice[j][2]);
		glutSolidSphere(0.1, 40, 40);
		glPopMatrix();
	}
}

//Para configurar la transformación de vista
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	/*Punto de la camara, centro de vista, vector hacia arriba*/
	//gluLookAt(cop_x, cop_y, cop_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glLoadMatrixf(Mx);
	GLfloat Mxx[16] = {0};
	for (int i = 0; i < 16; i++)
	{
		Mxx[i] = Mx[i];
	}
	
	glLoadMatrixf(Mxx);
	DibujarPiramide();
	dibujarcara();
	dibujarvertices();
	//glLoadMatrixf(Mx);
	//Transformaciones de modelado
	// glScalef (1.0, 2.0, 1.0);
	// glRotatef (30, 0.0, 0.0, 1.0);
	// Dibujar la geometria de los objetos de la escena



	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);


	glVertex3f(3.25, 1, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(3.25, 0, 0);
	glEnd();
	glFlush();
}
//Configura la transformación de proyeccion para cambios en la dimension de la ventana

//3 punto

//5 punto
void OpcMenu(int opción)
{
	GLfloat Mxxp[16] = { 0 };
	GLfloat Mxxo[16] = { 0 };

	switch (opción)
	{
	case 1:
		glViewport(0, 0, (GLsizei)500, (GLsizei)500);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glLoadMatrixf(Mx);
		gluPerspective(60.0, (float)500 / (float)500, 1.0, 300.0);
		//glLoadMatrixf(Mx);
		//glLoadMatrixf(Mp);
		glFlush();
		break;

	case 2:
		glViewport(0, 0, (GLsizei)500, (GLsizei)500);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glLoadMatrixf(Mp);
		glFlush();
		break;

	case 3:
		
		glViewport(0, 0, (GLsizei)500, (GLsizei)500);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glLoadMatrixf(Mo);
		glFlush();
		break;
	
	}

	glutPostRedisplay();
}



void Menu(void)
{
	int matriz = glutCreateMenu(OpcMenu);
	glutAddMenuEntry("MATRIZ DE VISUALIZACIÓN", 1);
	glutAddMenuEntry("MATRIZ DE PERSPECTIVA", 2);
	glutAddMenuEntry("MATRIZ DE ORTOGONAL", 3);
	glutAddMenuEntry("Piramide", 4);
	glutCreateMenu(OpcMenu);
	glutAddSubMenu("Opciones Matrices", matriz);
	// glutAddSubMenu("Salir", 4); /
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape()
{
	glViewport(0, 0, (GLsizei)500, (GLsizei)500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);*/
	//gPerspective(60.0, (float)w / (float)h, 1.0, 300.0);
	glLoadMatrixf(Mp);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	Menu();
	//DibujarPiramide();
	//glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}