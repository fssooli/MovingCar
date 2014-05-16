
/** Load the specified bitmap file from disk and copy it into an OpenGL texture.
* Return the GLuint representing the texture.
*/
GLuint LoadTexture(const char * bitmap_file)
{
    GLuint texture = 0;
    bmpread_t bitmap;
    
    if(!bmpread(bitmap_file, 0, &bitmap))
    {
        fprintf(stderr, "%s: error loading bitmap file\n", bitmap_file);
        exit(1);
    }
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.width, bitmap.height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, bitmap.rgb_data);
    
    bmpread_free(&bitmap);
    
    return texture;
}


void wall() {
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    GLuint tex1 = LoadTexture("brick.bmp");
    glPushMatrix();
        glTranslatef(0.0f, -0.2f, -1.5f);
        glBindTexture(GL_TEXTURE_2D, tex1);
        glBegin(GL_POLYGON);                // start drawing a polygon
//            glVertex3f(5.0f, 0.15f, 0.0f);        // Top left
//            glVertex3f(5.0f, 0.5f, 0.0f);
//            glVertex3f(-5.0f, 0.5f, 0.0f);
//            glVertex3f(-5.0f, 0.15f, 0.0f);
//            //glVertex3f(-0.2f,0.1f, 0.0f);        // Bottom Right
//            //glVertex3f(-0.2f,-0.15f, 0.0f);		   // Bottom Left
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
        glEnd();
	glPopMatrix();
    
}
