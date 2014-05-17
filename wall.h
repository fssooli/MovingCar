
void wall() {
    glEnable(GL_TEXTURE_2D);
    GLuint tex1 = LoadTexture("Red_Brick_Wall.bmp");
    glPushMatrix();
        glTranslatef(0.0f, -0.2f, -1.5f);
        glBindTexture(GL_TEXTURE_2D, tex1);
        glBegin(GL_POLYGON);                // start drawing a polygon
            glTexCoord2f(5.0f, 0.15f);
            glVertex3f(5.0f, 0.15f, 0.0f);        // Top left
    
            glTexCoord2f(5.0f, 0.5f);
            glVertex3f(5.0f, 0.5f, 0.0f);
    
            glTexCoord2f(-5.0f, 0.5f);
            glVertex3f(-5.0f, 0.5f, 0.0f);
    
            glTexCoord2f(-5.0f, 0.15f);
            glVertex3f(-5.0f, 0.15f, 0.0f);
//            //glVertex3f(-0.2f,0.1f, 0.0f);        // Bottom Right
//            //glVertex3f(-0.2f,-0.15f, 0.0f);		   // Bottom Left
        glEnd();
	glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
}
