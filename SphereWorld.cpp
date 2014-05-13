#include "Common/OpenGLSB.h"	// System and OpenGL Stuff
#include "Common/GLTools.h"	// OpenGL toolkit
#include <math.h>

GLfloat FrontBlackLight= 0.29;
GLfloat BackBlackLight= -0.19;

GLfloat L1P1=-0.15f;
GLfloat L1P2= 0.0f;

GLfloat L7P1= -0.40f;
GLfloat L7P2= -0.25f;

GLfloat L8P1= -0.65f;
GLfloat L8P2= -0.50f;

GLfloat L9P1= -0.90f;
GLfloat L9P2= -0.75f;

GLfloat L2P1 = 0.10;
GLfloat L2P2 = 0.25;

GLfloat L3P1 = 0.35;
GLfloat L3P2 = 0.5;

GLfloat L4P1 = 0.6;
GLfloat L4P2 = 0.75;

GLfloat L5P1 = 0.85;
GLfloat L5P2 = 1.0;

GLfloat L6P1 = 1.10;
GLfloat L6P2 = 1.25;

GLfloat L10P1 = 1.35;
GLfloat L10P2 = 1.50;

GLfloat L11P1 = 1.60;
GLfloat L11P2 = 1.75;

void DrawGround(void)
    {
    GLfloat fExtent = 20.0f;
    GLfloat fStep = 1.0f;
    GLfloat y = -0.4f;
    GLint iStrip, iRun;
    
    for(iStrip = -fExtent; iStrip <= fExtent; iStrip += fStep)
        {
        glBegin(GL_TRIANGLE_STRIP);
            glNormal3f(0.0f, 1.0f, 0.0f);   // All Point up
            
            for(iRun = fExtent; iRun >= -fExtent; iRun -= fStep)
                {
                glVertex3f(iStrip, y, iRun);
                glVertex3f(iStrip + fStep, y, iRun);
                }
        glEnd();
        }
    }

void DrowCar()
{
	glBegin(GL_POLYGON);                // start drawing a polygon 
			glColor3f(0.0f,0.3f,0.5f);            // Set The Color To Red 
  
				glVertex3f(0.3f, -0.15f, 0.0f);        // Top left 
				glVertex3f(0.3f, 0.0f, 0.0f);    
				glVertex3f(0.1f, 0.1f, 0.0f);    
				glVertex3f(-0.1f, 0.1f, 0.0f);
				glVertex3f(-0.2f,0.1f, 0.0f);        // Bottom Right 
				glVertex3f(-0.2f,-0.15f, 0.0f);		   // Bottom Left     

			glEnd();
}

void DrowTires()
{	
			////////////Tire1
		glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);  
        glTranslatef(-0.1,-0.15,0.0); 
        glutSolidSphere (0.04, 30, 15);  
		glPopMatrix();

		glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);  
        glTranslatef(-0.1,-0.15,0.0); 
        glutSolidSphere (0.02, 30, 5);  
		glPopMatrix();

		///////////Tire2
		glPushMatrix();
        glColor3f(0.0, 0.0, 0.0); 
        glTranslatef(0.18,-0.15,0.0);  
        glutSolidSphere (0.04, 30, 15); 
		glPopMatrix();

		glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);  
        glTranslatef(0.18,-0.15,0.0); 
        glutSolidSphere (0.02, 30, 5);  
		glPopMatrix();
}

void drawSun(void) { 
		/////////////Sun
		glPushMatrix();
        glColor3f(1.0, 1.0, 0.0); 
        glTranslatef(-0.75,0.6,0.0); 
        glutSolidSphere (0.06, 20, 100);  
		glPopMatrix();
        } 
        

void RenderScene(void)
    {
    // Clear the window with current clearing color
	glClearColor(0.0, 0.7, 1.0, 1.0);	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    glPushMatrix();
		glColor3f(0.7f, 0.7f, 0.7f);
        DrawGround();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
			glColor3f(0.6f, 0.3f, 0.2f);            // Set The Color To Red 
			glBegin(GL_POLYGON);                // start drawing a polygon 
				glVertex3f(5.0f, 0.15f, 0.0f);        // Top left 
				glVertex3f(5.0f, 0.5f, 0.0f);    
				glVertex3f(-5.0f, 0.5f, 0.0f);    
				glVertex3f(-5.0f, 0.15f, 0.0f);
				//glVertex3f(-0.2f,0.1f, 0.0f);        // Bottom Right 
				//glVertex3f(-0.2f,-0.15f, 0.0f);		   // Bottom Left     

			glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
		drawSun();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L1P1, -0.1f);
			glVertex2f(L1P2, -0.1f);
			//glVertex2f(-0.55f, -0.03f);
			//glVertex2f(-0.7f, -0.03f);
			glEnd();
    glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L5P1, -0.1f);
			glVertex2f(L5P2, -0.1f);
			//glVertex2f(-0.55f, -0.03f);
			//glVertex2f(-0.7f, -0.03f);
			glEnd();
    glPopMatrix();

			glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L6P1, -0.1f);
			glVertex2f(L6P2, -0.1f);
			//glVertex2f(-0.55f, -0.03f);
			//glVertex2f(-0.7f, -0.03f);
			glEnd();
    glPopMatrix();

	glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L2P1, -0.1f);
			glVertex2f(L2P2, -0.1f);
			//glVertex2f(-0.3f, -0.03f);
			//glVertex2f(-0.45f, -0.03f);
			glEnd();
	glPopMatrix();


			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L3P1, -0.1f);
			glVertex2f(L3P2, -0.1f);
			//glVertex2f(0.35f, -0.03f);
			//glVertex2f(0.5f, -0.03f);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L4P1, -0.1f);
			glVertex2f(L4P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L7P1, -0.1f);
			glVertex2f(L7P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L8P1, -0.1f);
			glVertex2f(L8P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L9P1, -0.1f);
			glVertex2f(L9P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L10P1, -0.1f);
			glVertex2f(L10P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L11P1, -0.1f);
			glVertex2f(L11P2, -0.1f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();

			// النور الأمامي أصفر
	glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);  
		glTranslatef(0.29f, -0.25f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

			// النور الامامي أسود
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);  
		glTranslatef(FrontBlackLight, -0.25f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();


			// النور الخلفي أحمر1
	glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);  
		glTranslatef(-0.19f, -0.28f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

			// النور الخلفي أحمر2
	glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);  
		glTranslatef(-0.19f, -0.23f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

			// النور الخلفي أسود1
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);  
		glTranslatef(BackBlackLight, -0.28f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

			// النور الخلفي أسود2
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);  
		glTranslatef(BackBlackLight, -0.23f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
		DrowCar();
		
		DrowTires();
	glPopMatrix();


      
    // Do the buffer Swap
    glutSwapBuffers();
    glutPostRedisplay();
    }



// Respond to arrow keys by moving the camera frame of reference
void SpecialKeys(int key, int x, int y)
    {


    if(key == GLUT_KEY_RIGHT)
	{
		 L1P1-=0.10;
		 L1P2-=0.10;
		 L2P1-=0.10;
		 L2P2-=0.10;
 		 L3P1-=0.10;
		 L3P2-=0.10;
  		 L4P1-=0.10;
		 L4P2-=0.10;
		 L5P1-=0.10;
		 L5P2-=0.10;
 		 L6P1-=0.10;
		 L6P2-=0.10;
 		 L7P1-=0.10;
		 L7P2-=0.10;
 		 L8P1-=0.10;
		 L8P2-=0.10;
 		 L9P1-=0.10;
		 L9P2-=0.10;
 		 L10P1-=0.10;
		 L10P2-=0.10;
 		 L11P1-=0.10;
		 L11P2-=0.10;
	}     

    if(key == GLUT_KEY_LEFT)
	{
		 L1P1 +=0.10;
		 L1P2 +=0.10;
 		 L2P1 +=0.10;
		 L2P2 +=0.10;
  		 L3P1 +=0.10;
		 L3P2 +=0.10;
  		 L4P1 +=0.10;
		 L4P2 +=0.10;
		 L5P1 +=0.10;
		 L5P2 +=0.10;
 		 L6P1 +=0.10;
		 L6P2 +=0.10;
 		 L7P1 +=0.10;
		 L7P2 +=0.10;
 		 L8P1 +=0.10;
		 L8P2 +=0.10;
 		 L9P1 +=0.10;
		 L9P2 +=0.10;
 		 L10P1 +=0.10;
		 L10P2 +=0.10;
 		 L11P1 +=0.10;
		 L11P2 +=0.10;
	}

	if(key == GLUT_KEY_UP)
	{
		FrontBlackLight = 50;
		BackBlackLight = 50;
	}

	if(key == GLUT_KEY_DOWN)
	{
		FrontBlackLight = 0.29;
		BackBlackLight = -0.19;
	}
                        
    // Refresh the Window
    glutPostRedisplay();
    }


///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
    {
    // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(3,TimerFunction, 1);
    }

void ChangeSize(int w, int h)
    {
    GLfloat fAspect;

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);
        
    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
    // Set the clipping volume
    gluPerspective(35.0f, fAspect, 1.0f, 50.0f);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
    }

int main(int argc, char* argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("OpenGL SphereWorld Demo + Lights and Shadow");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	//glutFullScreen();
	//glutIdleFunc(&RenderScene); 


    //SetupRC();
    //glutTimerFunc(33, TimerFunction, 1);

    glutMainLoop();

    return 0;
    }

