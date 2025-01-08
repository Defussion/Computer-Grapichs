#ifdef _WIN32

#include "glut.h"

#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

GLfloat cop_x = 9.0;
GLfloat cop_y = 0.0;
GLfloat cop_z = 0.0;
GLfloat Mx[16];
GLfloat Mp[16];











//Funcion de inicializacion
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	Mx[0] = 0;
	Mx[1] = 0;
	Mx[2] = 1;
	Mx[3] = 1;
	Mx[4] = 0;
	Mx[5] = -1;
	Mx[6] = 0;
	Mx[7] = 0;
	Mx[8] = -1;
	Mx[9] = 0;
	Mx[10] = 0;
	Mx[11] = 0;
	Mx[12] = 0;
	Mx[13] = 0;
	Mx[14] = -9;
	Mx[15] = 1;
	
	Mp[0] = 1/tan(0.524);
	Mp[1] = 0;
	Mp[2] = 0;
	Mp[3] = 0;
	Mp[4] = 0;
	Mp[5] = 1/tan(0.524);
	Mp[6] = 0;
	Mp[7] = 0;
	Mp[8] = 0;
	Mp[9] = 0;
	Mp[10] = -301/299;
	Mp[11] = -1;
	Mp[12] = 0;
	Mp[13] = 0;
	Mp[14] = -601/299;
	Mp[15] = 0;
	
}

//Para configurar la transformación de vista
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	//Punto de la camara, centro de vista, vector hacia arriba
	/*gluLookAt(cop_x, cop_y, cop_z, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);*/
	glLoadMatrixf(Mx);

	// Transformaciones de modelado
	// glScalef (1.0, 2.0, 1.0);
	// glRotatef (30, 0.0, 0.0, 1.0);
	// Dibujar la geometria de los objetos de la escena
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 1, 1);
	glEnd();
	glFlush();



}
//Configura la transformación de proyeccion para cambios en la dimension de la ventana
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	/*gluPerspective(60.0, (float)w / (float)h, 1.0, 300.0);*/
	glLoadMatrixf(Mp);
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