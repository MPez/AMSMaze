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

GLfloat X = 0;
GLfloat Y = 0;
GLfloat Z = 0;
GLfloat A = 0;


void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);

void DisegnaCubo(GLfloat R);
void DisegnaLineePavimento();


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(450, 450);
	glutCreateWindow(TITOLO);

	glEnable(GL_CULL_FACE);

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

	glRotatef(-A, 0, 1, 0);
	glTranslatef(-X, -Y, -Z);

	DisegnaLineePavimento();

	glColor3f(0.0f, 0.0f, 1.0f);
	DisegnaCubo(0.5f);


	glColor3f(1.0f, 0.0f, 0.0f);
	Cubo cubo(0.25f, 2.0f, 0.0f, 0.0f);
	cubo.disegna();

	glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
	glViewport(0, 0, w, h);

	// matrice
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.5, +0.5, -0.5, +0.5, 1, 1000);
}


void AzioneTasto(unsigned char t, int , int) 
{
	switch(t)
	{
		case('w'):
			Z -= (0.5f * cos(A / PI_180));
			X -= (0.5f * sin(A / PI_180));
			break;
		case('a'):
			X -= 0.5;
			break;
		case('s'):
			Z += (0.5f * cos(A / PI_180));
			X += (0.5f * sin(A / PI_180));
			break;
		case('d'):
			X += 0.5;
			break;
		case('q'):
			A += 5.0;
			break;
		case('e'):
			A -= 5.0;
			break;
	}
	
	glutPostRedisplay();
}

void DisegnaLineePavimento() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);

	for(GLfloat i = -200; i < 200; i += 5) {
		glVertex3f(-200, -2, i);
		glVertex3f(200, -2, i);
	}

	for(GLfloat i = -200; i < 200; i += 5) {
		glVertex3f(i, -2, -200);
		glVertex3f(i, -2, 200);
	}

	glEnd();
}

void DisegnaCubo(GLfloat R)
{
	glBegin(GL_QUADS);
	
	glNormal3f(0, 0, 1);
	glVertex3f(R, R, R);
	glVertex3f(-R, R, R);
	glVertex3f(-R, -R, R);
	glVertex3f(R, -R, R);
	
	glNormal3f(0, 0, -1);
	glVertex3f(-R, R, -R);
	glVertex3f(R, R, -R);
	glVertex3f(R, -R, -R);
	glVertex3f(-R, -R, -R);
	
	glNormal3f(1, 0, 0);
	glVertex3f(R, R, -R);
	glVertex3f(R, R, R);
	glVertex3f(R, -R, R);
	glVertex3f(R, -R, -R);
	
	glNormal3f(-1, 0, 0);
	glVertex3f(-R, R, R);
	glVertex3f(-R, R, -R);
	glVertex3f(-R, -R, -R);
	glVertex3f(-R, -R, R);
	
	glNormal3f(0, 1, 0);
	glVertex3f(R, R, -R);
	glVertex3f(-R, R, -R);
	glVertex3f(-R, R, R);
	glVertex3f(R, R, R);
	
	glNormal3f(0, -1, 0);
	glVertex3f(-R, -R, -R);
	glVertex3f(R, -R, -R);
	glVertex3f(R, -R, R);
	glVertex3f(-R, -R, R);
	
	glEnd();
}