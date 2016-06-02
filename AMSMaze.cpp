/**
 * Labirinto 3D
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "GL/glut.h"

#include <vector>

#include "Cubo.cpp"
#include "Parser.cpp"

static const char* TITOLO = "AMSMaze";
static const GLfloat PI_180 = 180.0f / 3.141592f;
static const GLfloat DIM_CUBO = 0.5f;

std::vector<int> maze;
Parser parser;
GLubyte brickTexture[256 * 256 *3];

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
void DisegnaMaze();
void DisegnaLuci();
void caricaTexture();
void ImpostaTexture();

int main(int argc, char *argv[])
{
	parser = Parser();
	maze = parser.parseInput("input_maze.txt");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(450, 450);
	glutCreateWindow(TITOLO);

	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	DisegnaLuci();
	caricaTexture();
	ImpostaTexture();

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
	glRotatef(-camera.ax, 1, 0, 0);
	glTranslatef(-camera.x, -camera.y, -camera.z);

	//DisegnaLineePavimento();

	//glColor3f(0.0f, 0.0f, 1.0f);
	// Cubo cubo1(0.5f, -1.0f, -1.5f, -2.0f);
	// cubo1.disegnaCentro();

	// Cubo cubo2(0.5f, -1.0f, -1.5f, -3.0f);
	// cubo2.disegnaCentro();

	// Cubo cubo3(0.5f, -1.0f, -1.5f, -4.0f);
	// cubo3.disegnaCentro();

	// Cubo cubo4(0.5f, 1.0f, -1.5f, -2.0f);
	// cubo4.disegnaCentro();

	// Cubo cubo5(0.5f, 1.0f, -1.5f, -3.0f);
	// cubo5.disegnaCentro();

	// Cubo cubo6(0.5f, 1.0f, -1.5f, -4.0f);
	// cubo6.disegnaCentro();




	Cubo::impostaMateriale();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	DisegnaMaze();


	glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 50);
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
			camera.y -= 0.5;
			break;
		case('c'):
			camera.y += 0.5;
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

void DisegnaMaze()
{
	for (int i = 0; i < parser.getRow(); ++i)
	{
		for (int j = 0; j < parser.getCol(); ++j)
		{
			if (maze[i * parser.getCol() + j])
			{
				Cubo cubo(DIM_CUBO, i, -1.5, -j);
				cubo.disegnaCentro();
			}
		}
	}
}

void DisegnaLuci()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightPosition[] = {10.0, 10.0, 0.0, 0.0};
	GLfloat ambientLight[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat diffuseLight[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void caricaTexture()
{
	FILE *texture = fopen("mattoni.raw", "rb");
	if (texture == NULL) {
		return;
	}
	fread(brickTexture, 256 *256, 3, texture);
	fclose(texture);
}

void ImpostaTexture()
{
	glBindTexture(GL_TEXTURE_2D, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, brickTexture);
    
}
