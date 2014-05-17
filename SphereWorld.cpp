#include "Common/OpenGLSB.h"	// System and OpenGL Stuff
#include "Common/GLTools.h"	// OpenGL toolkit
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include "libbmpread/bmpread.h"
#include "loadTexture.h"

/* START objects */
#include "wall.h"
/* END objects */

// escape key (for exit)
#define ESC 27

GLfloat FrontBlackLight= 0.29;
GLfloat BackBlackLight= -0.19;
GLfloat BackWhiteLight= 50;

GLfloat Line = -5;


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
	glBegin(GL_POLYGON);            
			glColor3f(0.0f,0.3f,0.5f);  
  
				glVertex3f(0.3f, -0.15f, 0.0f);     
				glVertex3f(0.3f, 0.0f, 0.0f);    
				glVertex3f(0.1f, 0.1f, 0.0f);    
				glVertex3f(-0.1f, 0.1f, 0.0f);
				glVertex3f(-0.2f,0.1f, 0.0f);    
				glVertex3f(-0.2f,-0.15f, 0.0f);	    

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
        
void DrowLines()
{
	glTranslatef(0.0f, -0.2f, -1.5f);
	for(float i=Line; i<100; i = i+0.5)
	{		
			glLineWidth(15.0);
			glBegin(GL_LINES);
			glColor3f( 0.0f, 0.0f, 0.0f);
			glVertex2f(i, -0.2f);
			glVertex2f(i+0.2, -0.2f);
			glEnd();
	}
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


// wall

        wall();
        
	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
		drawSun();
	glPopMatrix();


// Front Light "Yallow"
	glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);  
		glTranslatef(0.29f, -0.25f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

// Front Light "Black"
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);  
		glTranslatef(FrontBlackLight, -0.25f, -1.5f);
        glutSolidSphere (0.02, 15, 5); 
	glPopMatrix();

// Back Light "Red"
	glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);  
		glTranslatef(-0.19f, -0.25f, -1.5f); 
		glutSolidCube(0.04);
	glPopMatrix();

// Back Light "Black"
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);  
		glTranslatef(BackBlackLight, -0.25f, -1.5f); 
		glutSolidCube(0.04);
	glPopMatrix();

// Back Light "White"
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);  
		glTranslatef(BackWhiteLight, -0.25f, -1.5f); 
		glutSolidCube(0.02);
	glPopMatrix();


// Drow MidLines
	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.5f);
		DrowLines();
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
		 BackWhiteLight = 50;
		 Line-=0.10;
	}     

    if(key == GLUT_KEY_LEFT)
	{
		BackWhiteLight = -0.20;
		Line+=0.10;
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

/**
 Handel the quit key
 */
void processNormalKeys(unsigned char key, int xx, int yy)
{
    if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char* argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("OpenGL SphereWorld Demo + Lights and Shadow");
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	//glutFullScreen();
	//glutIdleFunc(&RenderScene); 


    //SetupRC();
    //glutTimerFunc(33, TimerFunction, 1);

    glutMainLoop();

    return 0;
    }

