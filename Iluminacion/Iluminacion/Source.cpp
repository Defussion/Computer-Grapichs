#ifdef _WIN32
#include "glut.h"
#elif defidned(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



using namespace std;

GLfloat cop_x = 5.0;
GLfloat cop_y = 5.0;
GLfloat cop_z = 5.0;

GLfloat light_ambient[] = { 0.5 , 0.5 , 0.5 , 1.0 };
GLfloat light_diffuse[] = { 0.4 , 0.4 , 0.4 , 1.0 };
GLfloat light_specular[] = { 0.7 , 0.7, 0.7 , 1.0 };
GLfloat light_position[] = { 1.0 , 4.0 , 4.0 , 1.0 };
void IluminacionGlobal()
{
	GLfloat global_ambient[] = { 0.9 , 0.9 , 0.9, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glEnable(GL_LIGHTING);
}
void IluminaciionPuntual() {
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}
void Lampara()
{
	/*GLfloat spot_position[] = { 0.0 , 0.0 , 4.0,1 };
	GLfloat direccion[] = { 0,0,-1,1 };*/
	/*GLfloat spot_position[] = { -3.0 , 0.0 , 0.0,1 };
	GLfloat direccion[] = { 1,0,-0.5,1 };*/
	GLfloat spot_position[] = { 3.0 , 0.0 , 0.0,1 };
	GLfloat direccion[] = { -1,0,-1,1 };
	//lampara
	glLightfv(GL_LIGHT1, GL_POSITION, spot_position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direccion);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 35.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);


	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.01);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.001);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.005);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	//
	 }
typedef struct materialStruct
{
	GLfloat ambient[4];
	GLfloat difusse[4];
	GLfloat specular[4];
	GLfloat shininess[1]; ;
} materialStruct;

materialStruct laton =
{
	0.33 , 0.22 , 0.03  , 1.0 ,
	0.78 , 0.57 , 0.11 , 1.0 ,
	0.99 , 0.91 , 0.81 , 1.0 ,
	27.8
};
void AsignarMaterial(materialStruct* material)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material->difusse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material->specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, material->shininess);
}
//Funcion de inicializacion
void init(void)
{
	/*IluminacionGlobal();
	IluminaciionPuntual();*/
	AsignarMaterial(&laton);
	Lampara();
	glEnable(GL_DEPTH_TEST);
	
}
void Emisividad()
{
	GLfloat emission[] = { 0.58 , 0.58 , 0.58 , 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
	glEnable(GL_LIGHTING);
}

//Para configurar la transformación de vista
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glColor3f(1, 0, 0);
	
		glLoadIdentity();
		gluLookAt(cop_x, cop_y, cop_z, 0, 0, 0, 0, 1, 0);

		glColor3f(0, 0, 1);
		glutSolidSphere(1, 50, 50);
		Emisividad();
		glTranslatef(2.2, 0, 0);
		glBegin(GL_QUADS);

		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
		glEnd();
	
		
		glFlush();
	}


//Configura la transformación de proyeccion para cambios en la dimension de la ventana
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 300.0);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}


