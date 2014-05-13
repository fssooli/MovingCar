#ifdef MACOSX
#include <GLUT/glut.h>
#endif

#include "Common/OpenGLSB.h"	// System and OpenGL Stuff
#include "Common/GLTools.h"	// OpenGL toolkit
#include <math.h>

#define SCREEN_X    800;
#define SCREEN_Y    600;
///////////////////////////////////////////////////
// Called to draw scene
GLfloat angle = 0.0f;
GLint size=3;
GLfloat L1P1=-0.55f;
GLfloat L1P2=-0.7f;

GLfloat L2P1 = -0.3f;
GLfloat L2P2 = -0.45;

GLfloat L3P1 = 0.35;
GLfloat L3P2 = 0.5;

GLfloat L4P1 = 0.6;
GLfloat L4P2 = 0.75;

int* coloringi = new int[size];

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
        glutSolidSphere (0.04, 15, 5);  
		glPopMatrix();

		///////////Tire2
		glPushMatrix();
        glColor3f(0.0, 0.0, 0.0); 
        glTranslatef(0.18,-0.15,0.0);  
        glutSolidSphere (0.04, 15, 5); 
		glPopMatrix();
}

void drawBall(void) { 
		/////////////Sun
		glPushMatrix();
        glColor3f(1.0, 1.0, 0.0); 
        glTranslatef(-0.75,0.6,0.0); 
        glutSolidSphere (0.06, 20, 100);  
		glPopMatrix();
		/*
		///////////MidLine1
			glPushMatrix();
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(0.6f, -0.03f);
			glVertex2f(0.75f, -0.03f);
			glEnd();
			glPopMatrix();
	
		///////////MidLine2
			glPushMatrix();
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(0.35f, -0.03f);
			glVertex2f(0.5f, -0.03f);
			glEnd();
			glPopMatrix();
	
		///////////MidLine3
			glPushMatrix();
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(-0.3f, -0.03f);
			glVertex2f(-0.45f, -0.03f);
			glEnd();
			glPopMatrix();

		///////////MidLine4
			glPushMatrix();
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(-0.55f, -0.03f);
			glVertex2f(-0.7f, -0.03f);
			glEnd();
			glPopMatrix();
			*/
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
		drawBall();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L1P1, -0.03f);
			glVertex2f(L1P2, -0.03f);
			//glVertex2f(-0.55f, -0.03f);
			//glVertex2f(-0.7f, -0.03f);
			glEnd();
    glPopMatrix();


	glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L2P1, -0.03f);
			glVertex2f(L2P2, -0.03f);
			//glVertex2f(-0.3f, -0.03f);
			//glVertex2f(-0.45f, -0.03f);
			glEnd();
	glPopMatrix();


			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L3P1, -0.03f);
			glVertex2f(L3P2, -0.03f);
			//glVertex2f(0.35f, -0.03f);
			//glVertex2f(0.5f, -0.03f);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0f, -0.2f, -1.5f);
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(L4P1, -0.03f);
			glVertex2f(L4P2, -0.03f);
			//glVertex2f(0.6f, -0.03f);
			//glVertex2f(0.75f, -0.03f);
			glEnd();
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


    if(key == GLUT_KEY_LEFT)
	{
		 L1P1-=0.10;
		 L1P2-=0.10;
		 L2P1-=0.10;
		 L2P2-=0.10;
 		 L3P1-=0.10;
		 L3P2-=0.10;
  		 L4P1-=0.10;
		 L4P2-=0.10;
	}     

    if(key == GLUT_KEY_RIGHT)
	{
		 L1P1 += 0.10f;
		 L1P2 +=0.10;
 		 L2P1 +=0.10;
		 L2P2 +=0.10;
  		 L3P1 +=0.10;
		 L3P2 +=0.10;
  		 L4P1 +=0.10;
		 L4P2 +=0.10;
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
	glutFullScreen();
	//glutIdleFunc(&RenderScene); 


    //SetupRC();
    //glutTimerFunc(33, TimerFunction, 1);

    glutMainLoop();

    return 0;
    }

