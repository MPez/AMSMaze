class Cubo
{
private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat a;
	GLfloat dim;

public:
	Cubo(GLfloat dim, GLfloat x, GLfloat y, GLfloat z) 
		: dim(dim), x(x), y(y), z(z), a(0) {}
	~Cubo() {}

	void disegnaCentro()
	{
		glPushMatrix();

		glTranslatef(x, y, z);
		glRotatef(a, 0, 1, 0);

		glBegin(GL_QUADS);
	
		glNormal3f(0, 0, 1);
		glVertex3f(dim, dim, dim);
		glVertex3f(-dim, dim, dim);
		glVertex3f(-dim, -dim, dim);
		glVertex3f(dim, -dim, dim);
		
		glNormal3f(0, 0, -1);
		glVertex3f(-dim, dim, -dim);
		glVertex3f(dim, dim, -dim);
		glVertex3f(dim, -dim, -dim);
		glVertex3f(-dim, -dim, -dim);
		
		glNormal3f(1, 0, 0);
		glVertex3f(dim, dim, -dim);
		glVertex3f(dim, dim, dim);
		glVertex3f(dim, -dim, dim);
		glVertex3f(dim, -dim, -dim);
		
		glNormal3f(-1, 0, 0);
		glVertex3f(-dim, dim, dim);
		glVertex3f(-dim, dim, -dim);
		glVertex3f(-dim, -dim, -dim);
		glVertex3f(-dim, -dim, dim);
		
		glNormal3f(0, 1, 0);
		glVertex3f(dim, dim, -dim);
		glVertex3f(-dim, dim, -dim);
		glVertex3f(-dim, dim, dim);
		glVertex3f(dim, dim, dim);
		
		glNormal3f(0, -1, 0);
		glVertex3f(-dim, -dim, -dim);
		glVertex3f(dim, -dim, -dim);
		glVertex3f(dim, -dim, dim);
		glVertex3f(-dim, -dim, dim);
		
		glEnd();

		glPopMatrix();
	}

	void disegnaTerra()
	{
		glPushMatrix();

		glTranslatef(x, y, z);
		glRotatef(a, 0, 1, 0);

		glBegin(GL_QUADS);
	
		glNormal3f(0, 0, 1);
		glVertex3f(dim, dim, dim);
		glVertex3f(0, dim, dim);
		glVertex3f(0, 0, dim);
		glVertex3f(dim, 0, dim);
		
		glNormal3f(0, 0, -1);
		glVertex3f(0, dim, 0);
		glVertex3f(dim, dim, 0);
		glVertex3f(dim, 0, 0);
		glVertex3f(0, 0, 0);
		
		glNormal3f(1, 0, 0);
		glVertex3f(dim, dim, 0);
		glVertex3f(dim, dim, dim);
		glVertex3f(dim, 0, dim);
		glVertex3f(dim, 0, 0);
		
		glNormal3f(-1, 0, 0);
		glVertex3f(0, dim, dim);
		glVertex3f(0, dim, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, dim);
		
		glNormal3f(0, 1, 0);
		glVertex3f(dim, dim, 0);
		glVertex3f(0, dim, 0);
		glVertex3f(0, dim, dim);
		glVertex3f(dim, dim, dim);
		
		glNormal3f(0, -1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(dim, 0, 0);
		glVertex3f(dim, 0, dim);
		glVertex3f(0, 0, dim);
		
		glEnd();

		glPopMatrix();	
	}
	
};