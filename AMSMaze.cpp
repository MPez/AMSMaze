/**
 * Labirinto 3D
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "GL/glut.h"
#include "Cubo.cpp"

static const char* TITOLO = "AMSMaze";
static const GLfloat PI_180 = 180.0f / 3.141592f;

struct
{
	GLfloat x = 0;
	GLfloat y = -1.5;
	GLfloat z = 0;
	GLfloat ay = 0;
	GLfloat ax = 0;
} camera;



void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);

void DisegnaLineePavimento();


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(450, 450);
	glutCreateWindow(TITOLO);

	glEnable(GL_CULL_FACE);

	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_NORMAL_ARRAY);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glutReshapeFunc(CambiaDimensione);
	glutDisplayFunc(DisegnaTutto);
	glutKeyboardFunc(AzioneTasto);
	
	glutMainLoop();

	return 0;
}

void DisegnaTutto()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(-camera.ay, 0, 1, 0);
	glRotatef(camera.ax, 1, 0, 0);
	glTranslatef(-camera.x, -camera.y, -camera.z);

	DisegnaLineePavimento();

	glColor3f(0.0f, 0.0f, 1.0f);
	Cubo cubo1(0.5f, -1.0f, -1.5f, -2.0f);
	cubo1.disegnaCentro();

	Cubo cubo2(0.5f, -1.0f, -1.5f, -3.0f);
	cubo2.disegnaCentro();

	Cubo cubo3(0.5f, -1.0f, -1.5f, -4.0f);
	cubo3.disegnaCentro();

	Cubo cubo4(0.5f, 1.0f, -1.5f, -2.0f);
	cubo4.disegnaCentro();

	Cubo cubo5(0.5f, 1.0f, -1.5f, -3.0f);
	cubo5.disegnaCentro();

	Cubo cubo6(0.5f, 1.0f, -1.5f, -4.0f);
	cubo6.disegnaCentro();


	glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 500);
	//gluPerspective(30, 1.0, 1.0, 20.0);
}


void AzioneTasto(unsigned char t, int , int) 
{
	switch(t)
	{
		case('w'):
			camera.z -= (0.5f * cos(camera.ay / PI_180));
			camera.x -= (0.5f * sin(camera.ay / PI_180));
			break;
		case('a'):
			camera.x -= (0.5f * cos(-camera.ay / PI_180));
			camera.z -= (0.5f * sin(-camera.ay / PI_180));
			break;
		case('s'):
			camera.z += (0.5f * cos(camera.ay / PI_180));
			camera.x += (0.5f * sin(camera.ay / PI_180));
			break;
		case('d'):
			camera.x += (0.5f * cos(-camera.ay / PI_180));
			camera.z += (0.5f * sin(-camera.ay / PI_180));
			break;
		case('q'):
			camera.ay += 5.0;
			break;
		case('e'):
			camera.ay -= 5.0;
			break;
		case('z'):
			camera.ax += 1.0;
			break;
		case('c'):
			camera.ax -= 1.0;
			break;
	}
	
	glutPostRedisplay();
}

void DisegnaLineePavimento() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);

	for(GLfloat i = -200; i < 200; i += 1) {
		glVertex3f(-200, -2, i);
		glVertex3f(200, -2, i);
	}

	for(GLfloat i = -200; i < 200; i += 1) {
		glVertex3f(i, -2, -200);
		glVertex3f(i, -2, 200);
	}

	glEnd();
}
