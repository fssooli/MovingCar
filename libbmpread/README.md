libbmpread
==========

libbmpread is a tiny, fast bitmap (.bmp) image file loader, written from
scratch in portable ANSI C.  Its default behavior is compatible with OpenGL
texture functions, making it ideal for use in simple games.  It handles
uncompressed monochrome, 16- and 256-color, and 24-bit bitmap files of any size
(no RLE support yet).

<https://github.com/chazomaticus/libbmpread>

Documentation
-------------

See `bmpread.h` for thorough documentation of the interface.  The main points
are:
* `bmpread_t` - struct that holds bitmap data
* `bmpread()` - read bitmap data from disk into a `bmpread_t`
* `bmpread_free()` - free memory allocated in `bmpread()`

Here's a code snippet showing how libbmpread might be used to create an OpenGL
texture from a bitmap file on disk:

```c
#include <stdio.h>
#include <GL/gl.h>
#include "bmpread.h"

/* Load the specified bitmap file from disk and copy it into an OpenGL texture.
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

void SomeInitFunction(void)
{
    GLuint tex1 = LoadTexture("texture1.bmp");
    // ...
}
```


Enjoy!
