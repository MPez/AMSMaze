#include <stdio.h>

class Cubo
{
private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat dim;
	GLfloat l;
	GLfloat w;
	GLfloat h;

public:
	Cubo(GLfloat dim, GLfloat x, GLfloat y, GLfloat z) 
		: dim(dim), x(x), y(y), z(z) {}

	Cubo(GLfloat l, GLfloat w, GLfloat h, GLfloat x, GLfloat y, GLfloat z) 
		: l(l), w(w), h(h), x(x), y(y), z(z) {}

	~Cubo() {}

	static void impostaMateriale(char material)
	{

		GLfloat ambientMaterial[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat diffuseMaterial[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat specularMaterial_mattoni[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat specularMaterial_legno[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shineMaterial[] = {30.0};

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
		switch(material) {
			case 'm':
				glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial_mattoni);
				break;
			case 'l':
				glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial_legno);
			break;
		}
		glMaterialfv(GL_FRONT, GL_SHININESS, shineMaterial);
	}

	void disegna1()
	{
		glPushMatrix();

		glTranslatef(x, y, z);

		glBegin(GL_QUADS);
	
		glNormal3f(0, 0, 1);
		glTexCoord2f(1, 1);
		glVertex3f(dim, dim, dim);
		glTexCoord2f(0, 1);
		glVertex3f(-dim, dim, dim);
		glTexCoord2f(0, 0);
		glVertex3f(-dim, -dim, dim);
		glTexCoord2f(1, 0);
		glVertex3f(dim, -dim, dim);
		
		glNormal3f(0, 0, -1);
		glTexCoord2f(1, 1);
		glVertex3f(-dim, dim, -dim);
		glTexCoord2f(0, 1);
		glVertex3f(dim, dim, -dim);
		glTexCoord2f(0, 0);
		glVertex3f(dim, -dim, -dim);
		glTexCoord2f(1, 0);
		glVertex3f(-dim, -dim, -dim);
		
		glNormal3f(1, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f(dim, dim, -dim);
		glTexCoord2f(0, 1);
		glVertex3f(dim, dim, dim);
		glTexCoord2f(0, 0);
		glVertex3f(dim, -dim, dim);
		glTexCoord2f(1, 0);
		glVertex3f(dim, -dim, -dim);
		
		glNormal3f(-1, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-dim, dim, dim);
		glTexCoord2f(0, 1);
		glVertex3f(-dim, dim, -dim);
		glTexCoord2f(0, 0);
		glVertex3f(-dim, -dim, -dim);
		glTexCoord2f(1, 0);
		glVertex3f(-dim, -dim, dim);
		
		glNormal3f(0, 1, 0);
		glTexCoord2f(1, 1);
		glVertex3f(dim, dim, -dim);
		glTexCoord2f(0, 1);
		glVertex3f(-dim, dim, -dim);
		glTexCoord2f(0, 0);
		glVertex3f(-dim, dim, dim);
		glTexCoord2f(1, 0);
		glVertex3f(dim, dim, dim);
		
		glNormal3f(0, -1, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-dim, -dim, -dim);
		glTexCoord2f(0, 1);
		glVertex3f(dim, -dim, -dim);
		glTexCoord2f(0, 0);
		glVertex3f(dim, -dim, dim);
		glTexCoord2f(1, 0);
		glVertex3f(-dim, -dim, dim);
		
		glEnd();

		glPopMatrix();
	}

	void disegna3()
	{
		glPushMatrix();

		glTranslatef(x, y, z);

		glBegin(GL_QUADS);
	
		glNormal3f(0, 0, 1);
		glTexCoord2f(1, 1);
		glVertex3f(l, h, w);
		glTexCoord2f(0, 1);
		glVertex3f(-l, h, w);
		glTexCoord2f(0, 0);
		glVertex3f(-l, -h, w);
		glTexCoord2f(1, 0);
		glVertex3f(l, -h, w);
		
		glNormal3f(0, 0, -1);
		glTexCoord2f(1, 1);
		glVertex3f(-l, h, -w);
		glTexCoord2f(0, 1);
		glVertex3f(l, h, -w);
		glTexCoord2f(0, 0);
		glVertex3f(l, -h, -w);
		glTexCoord2f(1, 0);
		glVertex3f(-l, -h, -w);
		
		glNormal3f(1, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f(l, h, -w);
		glTexCoord2f(0, 1);
		glVertex3f(l, h, w);
		glTexCoord2f(0, 0);
		glVertex3f(l, -h, w);
		glTexCoord2f(1, 0);
		glVertex3f(l, -h, -w);
		
		glNormal3f(-1, 0, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-l, h, w);
		glTexCoord2f(0, 1);
		glVertex3f(-l, h, -w);
		glTexCoord2f(0, 0);
		glVertex3f(-l, -h, -w);
		glTexCoord2f(1, 0);
		glVertex3f(-l, -h, w);
		
		glNormal3f(0, 1, 0);
		glTexCoord2f(1, 1);
		glVertex3f(l, h, -w);
		glTexCoord2f(0, 1);
		glVertex3f(-l, h, -w);
		glTexCoord2f(0, 0);
		glVertex3f(-l, h, w);
		glTexCoord2f(1, 0);
		glVertex3f(l, h, w);
		
		glNormal3f(0, -1, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-l, -h, -w);
		glTexCoord2f(0, 1);
		glVertex3f(l, -h, -w);
		glTexCoord2f(0, 0);
		glVertex3f(l, -h, w);
		glTexCoord2f(1, 0);
		glVertex3f(-l, -h, w);
		
		glEnd();

		glPopMatrix();
	}
};