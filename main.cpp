/**
 * Labirinto 3D
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <GL/glut.h>

#include "Cubo.h"
#include "Maze.h"
#include "Game.h"

struct
{
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	GLfloat z = 0.0f;
	GLfloat ay = 0.0f;
	GLfloat ax = 0.0f;
} camera;


struct
{
	int prev_x = 0;
	int prev_z = 0;
	int cur_x = 0;
	int cur_z = 0;
} posizione;

void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);

void DisegnaLineePavimento();
void DisegnaMaze(GLfloat dim);
void DisegnaPavimento(GLfloat dim);
void DisegnaLuci();
void caricaTexture();
void ImpostaTexture();
bool controllaSpostamento(GLfloat x, GLfloat z);

int main(int argc, char *argv[])
{
	Maze maze();
	maze.parseInput("input_maze.txt");

	camera.x = parser.getStart_c() - 1.0f;
	camera.z = -parser.getStart_r() + 1.0f;
	camera.y = DIM_CUBO;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(450, 450);
	glutCreateWindow(TITOLO);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

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

	printf("x: %f, y: %f, z: %f, a: %f\n\n", 
		camera.x, camera.y, camera.z, camera.ay);

	DisegnaLineePavimento();

	glEnable(GL_TEXTURE_2D);

	Cubo::impostaMateriale('m');
	glBindTexture(GL_TEXTURE_2D, 1);
	DisegnaMaze(DIM_CUBO);

	Cubo::impostaMateriale('l');
	glBindTexture(GL_TEXTURE_2D, 2);
	DisegnaPavimento(DIM_CUBO);



	glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 100);
	//gluPerspective(30, 1.0, 1.0, 20.0);
}


void AzioneTasto(unsigned char t, int , int) 
{
	switch(t)
	{
		case('w'):
			{
				GLfloat z = -SPOSTAMENTO * cos(camera.ay / PI_180);
				GLfloat x = -SPOSTAMENTO * sin(camera.ay / PI_180);
				printf("Spostamento x: %f, z: %f\n", x, z);
				if (controllaSpostamento(x, z))
				{
					camera.z += z;
					camera.x += x;
					printf("Passo avanti\n");
					//printf("Spostamento x: %f, z: %f\n", x, z);
					//aggiornaPosizione(x, z);
				} else
				{
					printf("Collisione muro avanti\n");
				}
			}
			break;
		case('a'):
			{
				GLfloat x = -SPOSTAMENTO * cos(-camera.ay / PI_180);
				GLfloat z = -SPOSTAMENTO * sin(-camera.ay / PI_180);
				printf("Spostamento x: %f, z: %f\n", x, z);
				if (controllaSpostamento(x, z))
				{
					camera.x += x;
					camera.z += z;
					printf("Passo sinistra\n");
				} else
				{
					printf("Collisione muro sinistra\n");
				}
				//printf("Spostamento x: %f, z: %f\n", x, z);
				//aggiornaPosizione(x, z);
			}
			break;
		case('s'):
			{
				GLfloat z = SPOSTAMENTO * cos(camera.ay / PI_180);
				GLfloat x = SPOSTAMENTO * sin(camera.ay / PI_180);
				printf("Spostamento x: %f, z: %f\n", x, z);
				if (controllaSpostamento(x, z))
				{
					camera.z += z;
					camera.x += x;
					printf("Passo indietro\n");
				} else 
				{
					printf("Collisione muro indietro\n");
				}
				//printf("Spostamento x: %f, z: %f\n", x, z);
				//aggiornaPosizione(x, z);
			}
			break;
		case('d'):
			{
				GLfloat x = SPOSTAMENTO * cos(-camera.ay / PI_180);
				GLfloat z = SPOSTAMENTO * sin(-camera.ay / PI_180);
				printf("Spostamento x: %f, z: %f\n", x, z);
				if (controllaSpostamento(x, z))
				{
					camera.x += x;
					camera.z += z;
					printf("Passo destra\n");
				} else 
				{
					printf("Collisione muro destra\n");
				}
				//printf("Spostamento x: %f, z: %f\n", x, z);
				//aggiornaPosizione(x, z);
			}
			break;
		case('q'):
			camera.ay += ANGOLO;
			printf("Gira sinistra\n");
			break;
		case('e'):
			camera.ay -= ANGOLO;
			printf("Gira destra\n");
			break;
		case('z'):
			camera.y -= 0.5;
			printf("Scendi\n");
			break;
		case('c'):
			camera.y += 0.5;
			printf("Sali\n");
			break;
	}
	
	glutPostRedisplay();
}

bool controllaSpostamento(GLfloat x, GLfloat z)
{
	int i;
	int j;

	i = (int) abs(round(camera.z + z));
	j = (int) abs(round(camera.x + x));


	printf("Controllo camera.z: %f, z: %f, camera.x: %f x: %f, i:%i, j: %i\n", 
		z, camera.z, x, camera.x, i, j);

	if (!Maze[i * parser.getCol() + j])
	{
		return true;
	}
	return false;
}

void DisegnaLineePavimento() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);

	for(GLfloat i = -200; i < 200; i += 1) {
		glVertex3f(-200, 0, i);
		glVertex3f(200, 0, i);
	}

	for(GLfloat i = -200; i < 200; i += 1) {
		glVertex3f(i, 0, -200);
		glVertex3f(i, 0, 200);
	}

	glEnd();
}

void DisegnaMaze(GLfloat dim)
{
	for (int i = 0; i < parser.getRow(); ++i)
	{
		for (int j = 0; j < parser.getCol(); ++j)
		{
			if (Maze[i * parser.getCol() + j])
			{
				Cubo cubo(dim, j, dim, -i - 1.0f);
				cubo.disegna1();
			}
		}
	}
}

void DisegnaPavimento(GLfloat dim)
{
	for (int i = 0; i < parser.getRow(); ++i)
		{
			for (int j = 0; j < parser.getCol(); ++j)
			{
				Cubo cubo1(dim, dim, 0.05f, j, -0.05f, -i - 1.0f);
				cubo1.disegna3();
			}
		}	
}

void DisegnaLuci()
{
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




