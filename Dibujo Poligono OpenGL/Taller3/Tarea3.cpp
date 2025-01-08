#include <iostream>;
#include "glut.h"
#include <math.h>
#include <stdio.h>
using namespace std;

GLfloat cop_x = 10.0;
GLfloat cop_y = 8.25;
GLfloat cop_z = 10.0;
GLfloat Mx[16];
GLfloat Mp[16];
GLfloat Mo[16];
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

	Mp[0] = tan(1.0472);
	Mp[1] = 0;
	Mp[2] = 0;
	Mp[3] = 0;

	Mp[4] = 0;
	Mp[5] = tan(1.0472);
	Mp[6] = 0;
	Mp[7] = 0;

	Mp[8] = 0;
	Mp[9] = 0;
	Mp[10] = -1;
	Mp[11] = -1;

	Mp[12] = 0;
	Mp[13] = 0;
	Mp[14] = -2;
	Mp[15] = 0;

	
	


}
//Para configurar la transformación de vista
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	/*Punto de la camara, centro de vista, vector hacia arriba*/
    /* gluLookAt(cop_x, cop_y, cop_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);*/
		glLoadMatrixf(Mx);

		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);


		glVertex3f(3.25, 1, 1);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(3.25, 0, 0);
		glEnd();
		glFlush();




	// Transformaciones de modelado
	// glScalef (1.0, 2.0, 1.0);
	// glRotatef (30, 0.0, 0.0, 1.0);
	// Dibujar la geometria de los objetos de la escena

}
//Configura la transformación de proyeccion para cambios en la dimension de la ventana
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    /*gluPerspective(60.0, (float)w / (float)h, 1.0, 300.0); Para comprobación*/
	//glOrtho(-6.5, 6.5, -6.5, 6.5, 1, 300);/**Para comprobación*/

		//glLoadMatrixf(Mp);
		//glFlush();


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

		Mo[12] = 0;
		Mo[13] = 0;
		Mo[14] = -1;
		Mo[15] = 1;
		glLoadMatrixf(Mo); //Matriz ortografica
		glFlush();

	
}

void menu(int id) {


}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutCreateMenu(menu);
	glutAddMenuEntry("Matriz de Visualizacion y Matriz de Perspectiva:Punto 1 y 2a", 2);
	glutAddMenuEntry("Matriz de Visualizacion y Matriz Ortografica:Punto 2b", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

#include<iostream>
#include<math.h>
#include"glut.h"

int Ancho = 500, Alto = 500, eje_x = Ancho / 2, eje_y = Ancho / 2;
int xi, xf, yi, yf, xp, yp;

void PintaPixel(float xi, float yi, float xf, float yf) {

    glPointSize(3);          //Grosor del pixel    
    glBegin(GL_LINES);      //Incio modo dibujo 
    glColor3f(1, 0, 0);    //Color pixel
    glVertex2f(xi, yi);   //Funciones de dibujo
    glVertex2f(xf, yf);
    glEnd();            //Cerrar funcion glBegin
    glutSwapBuffers(); //El pixel se queda en pantalla
}

void Plano() {

    glFlush();
}

void Perspectiva() {

    PintaPixel(4.31 * 20, -0.69 * 20, 0, 1.49 * 20);
    PintaPixel(0 * 20, 1.49 * 20, 0, 0);
    PintaPixel(0, 0, 4.31 * 20, -2.18 * 20);
    PintaPixel(4.31 * 20, -0.69 * 20, 4.31 * 20, -2.18 * 20);
}

void Ortogonal() {

    PintaPixel(0.373 * 200, -0.06 * 200, 0, 0.129 * 200);
    PintaPixel(0, 0.129 * 200, 0, 0);
    PintaPixel(0, 0, 0.373 * 200, -0.189 * 200);
    PintaPixel(0.373 * 200, -0.06 * 200, 0.373 * 200, -0.189 * 200);
}

void Menu(int menu) {

    if (menu == 1)
    {
        Perspectiva();
        glFlush();
    }
    if (menu == 2)
    {
        Ortogonal();
        glFlush();
    }
    if (menu == 3)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Plano();
    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);                         //Inicializar libreria
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  //Forma en la que se dibuja la ventana, color y buffer
    glutInitWindowSize(Ancho, Alto);             //Inicializar tamaÃ±o de la ventana    
    glutInitWindowPosition(100, 100);           //Ubicacion de la ventana        
    glutCreateWindow("VISTA 2D");              //Crear ventana y su nombre    
    gluOrtho2D(-eje_x, eje_x, -eje_y, eje_y); //Adecuar la ventana creada para dibujar, 4 parametros    
    glutCreateMenu(Menu);
    glutAddMenuEntry("Perspectiva", 1);
    glutAddMenuEntry("Ortogonal", 2);
    glutAddMenuEntry("Borrar", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(Plano); //Detener ventana
    glutMainLoop();        //Cerrar Ventana
}