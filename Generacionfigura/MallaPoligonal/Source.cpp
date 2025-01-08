#include <iostream>
#include "glut.h"

GLfloat vertice[8][3]; //LLENAR  8 vertices 3 datos (x,y,z)  8x3

void llenadovertice(){

vertice[0][0] = -1; vertice[0][1] = -1; vertice[0][2] = 1;
vertice[1][0] = 1;  vertice[1][1] = -1; vertice[1][2] = 1;
vertice[2][0] = 1;  vertice[2][1] = 1; vertice[2][2] = 1;
vertice[3][0] = -1;  vertice[3][1] = 1; vertice[3][2] = 1;
vertice[4][0] = -1;  vertice[4][1] = -1; vertice[4][2] = -1;
vertice[5][0] = 1;  vertice[5][1] = -1; vertice[5][2] = -1;
vertice[6][0] = 1;  vertice[6][1] = 1; vertice[6][2] = -1;
vertice[7][0] = -1;  vertice[7][1] = 1; vertice[7][2] = -1;


}
GLint caras[6][4] = {
{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };



GLint arista[12][2]; //LLENAR 12 aristas dos datos	

void llenadoarista() {

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
	


}

GLfloat colores[6][3];
void llenadocolores(){

	colores[0][0] = 1; colores[0][1] = 0; colores[0][2] = 0;    
	colores[1][0] = 0; colores[1][1] = 1; colores[1][2] = 0;    
	colores[2][0] = 0; colores[2][1] = 0; colores[2][2] = 1;    
	colores[3][0] = 0; colores[3][1] = 1; colores[3][2] = 1;     
	colores[4][0] = 1; colores[4][1] = 1; colores[4][2] = 0;     
	colores[5][0] = 1; colores[5][1] = 0; colores[5][2] = 1;
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
