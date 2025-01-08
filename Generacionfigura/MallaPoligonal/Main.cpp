#ifdef _WIN32
#include "glut.h"
#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
GLfloat cop_x = 5.0;
GLfloat cop_y = 5.0;
GLfloat cop_z = 5.0;

GLfloat colores[6][3];
GLfloat vertice[8][3];
GLint caras[6][4] = {
{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };

GLint arista[12][2]; //LLENAR 12 aristas dos datos	


//Funcion de inicializacion
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	vertice[0][0] = -1; vertice[0][1] = -1; vertice[0][2] = 1;
vertice[1][0] = 1;  vertice[1][1] = -1; vertice[1][2] = 1;
vertice[2][0] = 1;  vertice[2][1] = 1; vertice[2][2] = 1;
vertice[3][0] = -1;  vertice[3][1] = 1; vertice[3][2] = 1;
vertice[4][0] = -1;  vertice[4][1] = -1; vertice[4][2] = -1;
vertice[5][0] = 1;  vertice[5][1] = -1; vertice[5][2] = -1;
vertice[6][0] = 1;  vertice[6][1] = 1; vertice[6][2] = -1;
vertice[7][0] = -1;  vertice[7][1] = 1; vertice[7][2] = -1;


    colores[0][0] = 1; colores[0][1] = 0; colores[0][2] = 0;
	colores[1][0] = 0; colores[1][1] = 1; colores[1][2] = 0;    
	colores[2][0] = 0; colores[2][1] = 0; colores[2][2] = 1;    
	colores[3][0] = 0; colores[3][1] = 1; colores[3][2] = 1;     
	colores[4][0] = 1; colores[4][1] = 1; colores[4][2] = 0;     
	colores[5][0] = 1; colores[5][1] = 0; colores[5][2] = 1;
	arista[0][0] = 0;  arista[0][1] = 1;
		arista[1][0] = 1;  arista[1][1] = 5;
		arista[2][0] = 4;  arista[2][1] = 5;
		arista[3][0] = 4;  arista[3][1] = 0;
		arista[4][0] = 2;  arista[4][1] = 3;
		arista[5][0] = 2;  arista[5][1] = 6;
		arista[6][0] = 6;  arista[6][1] = 7;
		arista[7][0] = 7;  arista[7][1] = 3;
		arista[8][0] = 1;  arista[8][1] = 2;
		arista[9][0] = 5;  arista[9][1] = 6;
		arista[10][0] = 4;  arista[10][1] = 7;
		arista[11][0] = 0;  arista[11][1] = 3;
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
void dibujarista(void)
{
	for (int i = 0; i < 11; i++)
	{
		glBegin(GL_QUADS);
		glColor3fv(&colores[i % 6][0]);

		glVertex3f(vertice[arista[i][0]][0],arista[caras[i][0]][1], arista[caras[i][0]][2]);
		glVertex3f(vertice[arista[i][1]][0],arista[caras[i][1]][1], arista[caras[i][1]][2]);

		glEnd();
	}
}
void dibujarcara1(void)
{
	for (int i = 0; i < 6; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(colores[i][0], colores[i][1], colores[i][2]);

		glColor3fv(&colores[i][0]);
		glVertex3fv(&vertice[caras[i][0]][0]);
		glVertex3fv(&vertice[caras[i][1]][0]);
		glVertex3fv(&vertice[caras[i][2]][0]);

		glVertex3fv(&vertice[caras[i][3]][0]);
		glEnd();
	}
}

void dibujarvertices() {

	for (int j = 0; j < 8; j++)
	{
		glBegin(GL_POINTS);
		glVertex3fv(&vertice[j][0]);
			glEnd;
	}
}



//Para configurar la transformación de vista
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*glClear(GL_COLOR_BUFFER_BIT);*/
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	//Punto de la camara, centro de vista, vector hacia arriba
	gluLookAt(cop_x, cop_y, cop_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Transformaciones de modelado
	// glScalef (1.0, 2.0, 1.0);
	// glRotatef (30, 0.0, 0.0, 1.0);
	// Dibujar la geometria de los objetos de la escena
	/*glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	glEnd();*/

	//dibujarcara1();
	/*dibujarvertices();*/
	dibujarista();
	glFlush();
}
//Configura la transformación de proyeccion para cambios en la dimension de la ventana
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(60.0, (float)w / (float)h, 1.0, 300.0);
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
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}