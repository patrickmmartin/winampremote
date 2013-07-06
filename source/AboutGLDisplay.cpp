/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2012

Copyright (C) 2000,2001,2012  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/


/*
 * AboutGLDisplay.cpp
 *
 *  Created on: 6 Jul 2013
 *      Author: Patrick
 */

#include "AboutGLDisplay.h"

#include <GL\gl.h>
#include <GL\glu.h>
#include <math.h>  // TODO - really?
#include <malloc.h>  // TODO - really?


#define GLF_START_LIST 20000
#define TORUS 1
#define CUBE 2
#define SPHERE 3

AboutGLDisplay::AboutGLDisplay(HDC hDC_, int clientWidth_, int clientHeight_):
                                m_glOptions(),
                                glyphMetrics(),
                                hDC(hDC_), outText(),
                                clientWidth(clientWidth_), clientHeight(clientHeight_),
                                mode(MoveNone),
                		objectIndex(1), objectNumMajor(32), objectNumMinor(32)

{

    startup = GetTickCount();
    nowdraw = startup;

	outText.push_back("Winamp");
	outText.push_back("Remote");
	outText.push_back("Control");

    hGLRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hGLRC);

}

AboutGLDisplay::~AboutGLDisplay()
{
	  if (hGLRC) {
	      wglMakeCurrent(NULL, NULL);
	      wglDeleteContext(hGLRC);
	  }
}

AboutGLDisplay::GLOptions & AboutGLDisplay::gloptions()
{
	return m_glOptions;
}


void AboutGLDisplay::CreateFontList(){

  // create text display list
LOGFONT lf;
HFONT hFont, hOldFont;

    glMatrixMode(GL_MODELVIEW);

    //sets up a display list for entire character set selected into DC
    memset(&lf,0,sizeof(LOGFONT));
    lf.lfHeight               =   -48 ;
    lf.lfWeight               =   FW_BOLD ;
    lf.lfCharSet              =   ANSI_CHARSET ;
    lf.lfOutPrecision         =   OUT_DEFAULT_PRECIS ;
    lf.lfClipPrecision        =   CLIP_DEFAULT_PRECIS ;
    lf.lfQuality              =   DEFAULT_QUALITY ;
    lf.lfPitchAndFamily       =   FF_DONTCARE|DEFAULT_PITCH;
    lstrcpy (lf.lfFaceName, "Arial") ;

    hFont = CreateFontIndirect(&lf);
    hOldFont = SelectObject(hDC,hFont);

// Create a set of display lists based on the glyphs of the TT font we selected

/*
The wglUseFontOutlines function approximates glyph outlines
by subdividing the quadratic B-spline curves of the outline into line segments,
until the distance between the outline and the interpolated midpoint is within
the value specified by deviation.
This is the final format used when format is WGL_FONT_LINES.
When you specify WGL_FONT_OUTLINES, the display lists created don't contain
any normals; thus lighting doesn't work properly.
To get the correct lighting of lines use WGL_FONT_POLYGONS and set
glPolygonMode(GL_FRONT, GL_LINE).
When you specify format as WGL_FONT_POLYGONS the outlines are further
tessellated into separate triangles, triangle fans, triangle strips, or
quadrilateral strips to create the surface of each glyph.
With WGL_FONT_POLYGONS, the created display lists call glFrontFace(GL_CW)
or glFrontFace(GL_CCW); thus the current front-face value might be altered.
For the best appearance of text with WGL_FONT_POLYGONS, cull the back faces
as follows:


*/

glCullFace(GL_BACK);
glEnable(GL_CULL_FACE);

    // Create a set of display lists based on the glyphs of the TT font we selected
    if (!(wglUseFontOutlines(hDC, 0, 127, GLF_START_LIST, 0.0f, m_glOptions.textExtrusion,
       WGL_FONT_POLYGONS, glyphMetrics)))
      throw "wglUseFontOutlines failed!";

    DeleteObject(SelectObject(hDC,hOldFont));

  }

void AboutGLDisplay::CreateDisplayLists(void){
  // the cube
  glNewList(CUBE, GL_COMPILE);
    //
    // Draw the six faces of the cube.
    //
    glBegin(GL_QUADS);
    glNormal3f(-1.0F, 0.0F, 0.0F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f(-0.5F,-0.5F,-0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f(-0.5F,-0.5F, 0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f(-0.5F, 0.5F, 0.5F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f(-0.5F, 0.5F,-0.5F);

    glNormal3f( 1.0F, 0.0F, 0.0F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f( 0.5F, 0.5F, 0.5F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f( 0.5F,-0.5F, 0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f( 0.5F,-0.5F,-0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f( 0.5F, 0.5F,-0.5F);

    glNormal3f( 0.0F,-1.0F, 0.0F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f(-0.5F,-0.5F,-0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f( 0.5F,-0.5F,-0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f( 0.5F,-0.5F, 0.5F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f(-0.5F,-0.5F, 0.5F);

    glNormal3f( 0.0F, 1.0F, 0.0F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f( 0.5F, 0.5F, 0.5F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f( 0.5F, 0.5F,-0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f(-0.5F, 0.5F,-0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f(-0.5F, 0.5F, 0.5F);

    glNormal3f( 0.0F, 0.0F,-1.0F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f(-0.5F,-0.5F,-0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f(-0.5F, 0.5F,-0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f( 0.5F, 0.5F,-0.5F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f( 0.5F,-0.5F,-0.5F);

    glNormal3f( 0.0F, 0.0F, 1.0F);
    glTexCoord2f( 1.0F, 1.0F); glVertex3f( 0.5F, 0.5F, 0.5F);
    glTexCoord2f( 0.0F, 1.0F); glVertex3f(-0.5F, 0.5F, 0.5F);
    glTexCoord2f( 0.0F, 0.0F); glVertex3f(-0.5F,-0.5F, 0.5F);
    glTexCoord2f( 1.0F, 0.0F); glVertex3f( 0.5F,-0.5F, 0.5F);
    glEnd();
  glEndList();

  // the cube
  glNewList(SPHERE, GL_COMPILE);
  glEndList();

  // the cube
  glNewList(TORUS, GL_COMPILE);
  glEndList();

  }

void AboutGLDisplay::drawText(void){

 unsigned int index, i;

 double xoffset = 0;
 double yoffset;
 int textIndex;

  yoffset = glyphMetrics[0].gmfBlackBoxY;

  textIndex = ((GetTickCount() - startup) / 2000) % (outText.size());

  std::string text = outText[textIndex];
  for (i = 0 ; i < strlen(text.c_str()) ; i++)
  {
    // index into the glyph metrics to get the position info
    index = (int) outText[textIndex].c_str()[i];
    xoffset += glyphMetrics[index].gmfBlackBoxX;
  }

 // notes re text : face sense gets screwed (maybe)

      glTranslatef(-xoffset / 2, -yoffset / 2, m_glOptions.textExtrusion / 2);
      glListBase(GLF_START_LIST);
      glCallLists(strlen(text.c_str()), GL_UNSIGNED_BYTE, text.c_str());
      glListBase(0);
      glTranslatef(xoffset / 2, yoffset / 2, -m_glOptions.textExtrusion / 2);

  };

void AboutGLDisplay::drawCube(void)
{
    glPushMatrix(); //push nice view
      glScalef(1, 1, 1);
      glListBase(0);
      glCallList(CUBE);
    glPopMatrix(); //pop nice view
}

void AboutGLDisplay::drawTorus(void)
{
    struct vertex {
    GLfloat t[2];
	GLfloat n[3];
	GLfloat v[3];
    };

    int numVerts = (objectNumMajor+1) * (objectNumMinor+1);
    int numStrips = m_glOptions.halfObject ? objectNumMajor / 2 : objectNumMajor;
    int numPerStrip = 2 * (objectNumMinor+1);
    int numElements = (objectNumMajor+1) * numPerStrip;

    static struct vertex *vertexArray, *v;
    static GLuint *elementArray, *e;
    static int numMajor;
    static int numMinor;
    int i, j;

    if (!vertexArray || numMajor!=objectNumMajor || numMinor!=objectNumMinor) {
	float majorRadius = 0.6F;
	float minorRadius = 0.2F;
	double majorStep = 2.0F*M_PI / objectNumMajor;
	double minorStep = 2.0F*M_PI / objectNumMinor;

	if (vertexArray) free(vertexArray);
	vertexArray = (struct vertex *)
		calloc(numVerts, sizeof(struct vertex));

	if (elementArray) free(elementArray);
	elementArray = (GLuint *)
		calloc(numElements, sizeof(GLuint));

	numMajor = objectNumMajor;
	numMinor = objectNumMinor;

	v = vertexArray;
	e = elementArray;
	for (i=0; i<=numMajor; ++i) {
	    double a = i * majorStep;
	    GLfloat x = (GLfloat) cos(a);
	    GLfloat y = (GLfloat) sin(a);

	    for (j=0; j<=numMinor; ++j) {
		double b = j * minorStep;
		GLfloat c = (GLfloat) cos(b);
		GLfloat r = minorRadius * c + majorRadius;
		GLfloat z = minorRadius * (GLfloat) sin(b);

		v->t[0] = i/(GLfloat) numMajor;
		v->t[1] = j/(GLfloat) numMinor;

		v->n[0] = x*c;
		v->n[1] = y*c;
		v->n[2] = z/minorRadius;

		v->v[0] = x*r;
		v->v[1] = y*r;
		v->v[2] = z;

		v++;

		*e++ = i * (numMinor+1) + j;
		*e++ = (i+1) * (numMinor+1) + j;
	    }
	}
    }

    if (m_glOptions.useVertexArray) {
	glInterleavedArrays(GL_T2F_N3F_V3F, 0, vertexArray);

#if defined(GL_SGI_compiled_vertex_array)
	if (useVertexLocking && LockArrays) LockArrays(0, numVerts);
#endif

    for (i=0, e=elementArray; i<numStrips; ++i, e+=numPerStrip) {
        glDrawElements(GL_TRIANGLE_STRIP, numPerStrip, GL_UNSIGNED_INT, e);
    }

#if defined(GL_SGI_compiled_vertex_array)
	if (useVertexLocking && UnlockArrays) UnlockArrays();
#endif
    } else {
	for (i=0, e=elementArray; i<numStrips; ++i, e+=numPerStrip) {
	    glBegin(GL_TRIANGLE_STRIP);
	    for (j=0; j<numPerStrip; ++j) {
		v = &vertexArray[e[j]];

		glTexCoord2fv(v->t);
		glNormal3fv(v->n);
		glVertex3fv(v->v);
	    }
	    glEnd();
	}
    }
}

void AboutGLDisplay::drawSphere(void)
{
    struct vertex {
        GLfloat t[2];
	GLfloat n[3];
	GLfloat v[3];
    };

    int numVerts = (objectNumMajor+1) * (objectNumMinor+1);
    int numStrips = m_glOptions.halfObject ? objectNumMajor / 2 : objectNumMajor;
    int numPerStrip = 2 * (objectNumMinor+1);
    int numElements = (objectNumMajor+1) * numPerStrip;

    static struct vertex *vertexArray, *v;
    static GLuint *elementArray, *e;
    static int numMajor;
    static int numMinor;
    int i, j;

    if (!vertexArray || numMajor!=objectNumMajor || numMinor!=objectNumMinor) {
	float radius = 0.6F;
	double majorStep = 2.0F*M_PI / objectNumMajor;
	double minorStep = M_PI / objectNumMinor;

	if (vertexArray) free(vertexArray);
	vertexArray = (struct vertex *)
		calloc(numVerts, sizeof(struct vertex));

	if (elementArray) free(elementArray);
	elementArray = (GLuint *)
		calloc(numElements, sizeof(GLuint));

	numMajor = objectNumMajor;
	numMinor = objectNumMinor;

	v = vertexArray;
	e = elementArray;
	for (i=0; i<=numMajor; ++i) {
	    double a = i * majorStep;
	    GLfloat x = (GLfloat) cos(a);
	    GLfloat y = (GLfloat) sin(a);

	    for (j=0; j<=numMinor; ++j) {
		double b = j * minorStep;
		GLfloat c = (GLfloat) sin(b);
		GLfloat r = c * radius;
		GLfloat z = (GLfloat) cos(b);

		v->t[0] = i/(GLfloat) numMajor;
		v->t[1] = j/(GLfloat) numMinor;

		v->n[0] = x*c;
		v->n[1] = y*c;
		v->n[2] = z;

		v->v[0] = x*r;
		v->v[1] = y*r;
		v->v[2] = z*radius;

		v++;

		*e++ = (i+1) * (numMinor+1) + j;
		*e++ = i * (numMinor+1) + j;
	    }
	}
    }

    if (m_glOptions.useVertexArray) {
	glInterleavedArrays(GL_T2F_N3F_V3F, 0, vertexArray);

#if defined(GL_SGI_compiled_vertex_array)
	if (useVertexLocking && LockArrays) LockArrays(0, numVerts);
#endif

	for (i=0, e=elementArray; i<numStrips; ++i, e+=numPerStrip) {
	    glDrawElements(GL_TRIANGLE_STRIP, numPerStrip, GL_UNSIGNED_INT, e);
	}

#if defined(GL_SGI_compiled_vertex_array)
	if (useVertexLocking && UnlockArrays) UnlockArrays();
#endif
    } else {
	for (i=0, e=elementArray; i<numStrips; ++i, e+=numPerStrip) {
	    glBegin(GL_TRIANGLE_STRIP);
	    for (j=0; j<numPerStrip; ++j) {
		v = &vertexArray[e[j]];

		glTexCoord2fv(v->t);
		glNormal3fv(v->n);
		glVertex3fv(v->v);
	    }
	    glEnd();
	}
    }
}

void AboutGLDisplay::setCheckTexture(void)
{
    int texWidth = 256;
    int texHeight = 256;
    GLubyte *texPixels, *p;
    int texSize;
    int i, j;

    texSize = texWidth*texHeight*4*sizeof(GLubyte);
    if (m_glOptions.textureReplace) {
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    } else {
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texPixels = (GLubyte *) malloc(texSize);
    if (texPixels == NULL) {
	return;
    }

    p = texPixels;
    for (i=0; i<texHeight; ++i) {
	for (j=0; j<texWidth; ++j) {
	    if ((i ^ j) & 32) {
		p[0] = 0xff; p[1] = 0xff; p[2] = 0xff; p[3] = 0xff;
	    } else {
		p[0] = 0x10; p[1] = 0x10; p[2] = 0x10; p[3] = 0xff;
	    }
	    p += 4;
	}
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		 texWidth, texHeight, 0,
		 GL_RGBA, GL_UNSIGNED_BYTE, texPixels);

    free(texPixels);
}

void matrixIdentity(GLfloat m[4][4])
{
    m[0][0] = 1.0F; m[0][1] = 0.0F; m[0][2] = 0.0F; m[0][3] = 0.0F;
    m[1][0] = 0.0F; m[1][1] = 1.0F; m[1][2] = 0.0F; m[1][3] = 0.0F;
    m[2][0] = 0.0F; m[2][1] = 0.0F; m[2][2] = 1.0F; m[2][3] = 0.0F;
    m[3][0] = 0.0F; m[3][1] = 0.0F; m[3][2] = 0.0F; m[3][3] = 1.0F;
}

void AboutGLDisplay::setProjection(void)
{
    GLfloat aspect = (GLfloat) clientWidth / (GLfloat) clientHeight;


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0,           // Field-of-view angle
                 aspect,      // Aspect ratio of viewing volume
                 0.1,            // Distance to near clipping plane
                 100.0);          // Distance to far clipping plane
  glViewport(0, 0, clientWidth, clientHeight);


  glMatrixMode(GL_MODELVIEW);
}

void AboutGLDisplay::setMaterial(void)
{
    GLfloat matAmb[4] = { 0.01F, 0.01F, 0.01F, 1.00F };
    GLfloat matDiff[4] = { 0.45F, 0.05F, 0.65F, 0.60F };
    GLfloat matSpec[4] = { 0.50F, 0.50F, 0.50F, 1.00F };
    GLfloat matShine = 20.00F;

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, matShine);
}

void AboutGLDisplay::init(void)
{

    GLfloat light0Pos[4] = { 0.70F, 0.70F, 1.25F, 0.00F };
    GLfloat fogDensity = 1.35F*0.180F;

    GLfloat fogColor[4] = {
    /*
	0.4F, 0.4F, 0.5F, 1.0F,
     */
	0.0F, 0.0F, 0.0F, 1.0F,

    };

#if defined(GL_SGI_cull_vertex)
    CullParameterfv = (PFNGLCULLPARAMETERFVSGIPROC)
    	wglGetProcAddress("glCullParameterfvSGI");
#endif

#if defined(GL_SGI_compiled_vertex_array)
    LockArrays = (PFNGLLOCKARRAYSSGIPROC)
    	wglGetProcAddress("glLockArraysSGI");
    UnlockArrays = (PFNGLUNLOCKARRAYSSGIPROC)
    	wglGetProcAddress("glUnlockArraysSGI");
#endif

    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogf(GL_FOG_DENSITY, fogDensity);
    glFogfv(GL_FOG_COLOR, fogColor);

    setProjection();
    glTranslatef(0.0F, 0.0F, -2.0F);

    setMaterial();

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
    glEnable(GL_LIGHT0);

    setCheckTexture();

    matrixIdentity(objectXform);

    // TODO failure here
    CreateFontList();
    CreateDisplayLists();
}

void AboutGLDisplay::resize(void)
{
    setProjection();
    glViewport(0, 0, clientWidth, clientHeight);
}

void AboutGLDisplay::doRedraw(void)
{

 try{

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

    /* required for antialising */
//    glEnable(GL_BLEND);


/* "To antialias points or lines in Opengl,
you need to enable antialiasing by calling glEnable()
and passing in GL_POINT_SMOOTH or GL_LINE_SMOOTH,
as appropriate.
You can also provide a quality hint by calling glHint().
The hint parameter can be GL_FASTEST to indicate that
the most efficient option should be chosen,
GL_NICEST to indicate the highest quality option should be chosen,
or GL_DONT_CARE to indicate no preference.
*/


    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);


    glHint(GL_POINT_SMOOTH_HINT, GL_FASTEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);


  //constant background
    if (m_glOptions.useFog) {
//	glClearColor(0.4F, 0.4F, 0.5F, 1.0F);
	glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
	glEnable(GL_FOG);
    } else {
//	glClearColor(0.2F, 0.2F, 0.1F, 1.0F);
	glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
	glDisable(GL_FOG);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // update transformations
    if (mode == MoveObject) {
	glPushMatrix();
	glLoadIdentity();
	glRotatef( angle , axis[0], axis[1], axis[2]);	glMultMatrixf((GLfloat *) objectXform);
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) objectXform);
	glPopMatrix();
    }

    if (m_glOptions.textureEnabled) {
	glEnable(GL_TEXTURE_2D);
    }
    if (m_glOptions.drawOutlines) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
#if defined(GL_SGI_cull_vertex)
    if (useVertexCull) {
        glEnable(GL_CULL_VERTEX_SGI);
    }
#endif
    if (m_glOptions.useFaceCull) {
        glEnable(GL_CULL_FACE);
    }
    if (m_glOptions.useLighting) {
	glEnable(GL_LIGHTING);
    }
    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
    glTranslatef(xOffset, yOffset, 0.0F);
    glMultMatrixf((GLfloat *) objectXform);


    switch (objectIndex){
      case 0:
      glFrontFace(GL_CCW);
      drawTorus();
      break;
      case 1:
      glFrontFace(GL_CCW);
      drawSphere();
      break;
      case 2:
      glFrontFace(GL_CCW);
      drawCube();
      break;
      case 3:
      glFrontFace(GL_CW);
      drawText();
      break;
    }

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#if defined(GL_SGI_cull_vertex)
    glDisable(GL_CULL_VERTEX_SGI);
#endif
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glFlush();
    SwapBuffers(hDC);
    }
    catch ( ... )
    {
     // duuno
    }
}



void AboutGLDisplay::redraw(void)
{
  lastdraw = nowdraw;
  nowdraw = GetTickCount();
  doRedraw();
}




void AboutGLDisplay::ptov(int x, int y, int width, int height, float v[3])
{
    float d, a;

    // project x,y onto a hemi-sphere centered within width, height
    v[0] = (2.0F*x - width) / width;
    v[1] = (height - 2.0F*y) / height;
    d = (float) sqrt(v[0]*v[0] + v[1]*v[1]);
    v[2] = (float) cos((M_PI/2.0F) * ((d < 1.0F) ? d : 1.0F));
    a = 1.0F / (float) sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    v[0] *= a;
    v[1] *= a;
    v[2] *= a;
}

void AboutGLDisplay::startMotion(DWORD /* time */, int button, int x, int y)
{
    if (button == 1) {
	mode = MoveObject;
    } else {
	return;
    }

    trackingMotion = TRUE;
    startX = x;
    startY = y;
    ptov(x, y, clientWidth, clientHeight, lastPos);
}

void AboutGLDisplay::stopMotion(DWORD /* time */, int button, int x, int y)
{
    if (button == 1 && mode == MoveObject) {
	trackingMotion = FALSE;
    } else {
	return;
    }

    if (startX != x || startY != y) {
    } else {
	angle = 0.0F;
    }
}

void AboutGLDisplay::trackMotion(DWORD /* time */, int x, int y)
{
    if (trackingMotion) {
	float curPos[3], dx, dy, dz;

	ptov(x, y, clientWidth, clientHeight, curPos);

	dx = curPos[0] - lastPos[0];
	dy = curPos[1] - lastPos[1];
	dz = curPos[2] - lastPos[2];
	angle = 90.0F * (float) sqrt(dx*dx + dy*dy + dz*dz);

	axis[0] = lastPos[1]*curPos[2] - lastPos[2]*curPos[1];
	axis[1] = lastPos[2]*curPos[0] - lastPos[0]*curPos[2];
	axis[2] = lastPos[0]*curPos[1] - lastPos[1]*curPos[0];

	lastPos[0] = curPos[0];
	lastPos[1] = curPos[1];
	lastPos[2] = curPos[2];
    }
}



void AboutGLDisplay::setupPalette()
{
    PIXELFORMATDESCRIPTOR pfd;
    LOGPALETTE* pPal;
    int pixelFormat = GetPixelFormat(hDC);
    int paletteSize;

    DescribePixelFormat(hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    if (!((pfd.dwFlags & PFD_NEED_PALETTE) ||
    	  (pfd.iPixelType == PFD_TYPE_COLORINDEX)))
    {
	return;
    }

    paletteSize = 1 << pfd.cColorBits;
    pPal = (LOGPALETTE*)
	malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    pPal->palVersion = 0x300;
    pPal->palNumEntries = (WORD) paletteSize;

    // start with a copy of the current system palette
    (void) GetSystemPaletteEntries(hDC, 0, paletteSize, &pPal->palPalEntry[0]);

    {
	// fill in an RGBA color palette
	int redMask = (1 << pfd.cRedBits) - 1;
	int greenMask = (1 << pfd.cGreenBits) - 1;
	int blueMask = (1 << pfd.cBlueBits) - 1;
	int i;

	for (i=0; i<paletteSize; ++i) {
	    pPal->palPalEntry[i].peRed = (GLbyte)
		    ((((i >> pfd.cRedShift)
					& redMask) * 255) / redMask);
	    pPal->palPalEntry[i].peGreen = (GLbyte)
		    ((((i >> pfd.cGreenShift) & greenMask) * 255) / greenMask);
	    pPal->palPalEntry[i].peBlue = (GLbyte)
		    ((((i >> pfd.cBlueShift) & blueMask) * 255) / blueMask);
	    pPal->palPalEntry[i].peFlags = 0;
	}
    }

	HPALETTE hPalette;
    hPalette = CreatePalette(pPal);
    free(pPal);

    if (hPalette) {
	SelectPalette(hDC, hPalette, FALSE);
	RealizePalette(hDC);
    }
}

void AboutGLDisplay::setupPixelformat()
{
    PIXELFORMATDESCRIPTOR pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),	// size of this pfd
	1,				// version num
	PFD_DRAW_TO_WINDOW |		// support window
	PFD_SUPPORT_OPENGL,		// support OpenGL
	PFD_TYPE_RGBA,			// color type
	8,				// 8-bit color depth
	0, 0, 0, 0, 0, 0,		// color bits (ignored)
	0,				// no alpha buffer
	0,				// alpha bits (ignored)
	0,				// no accumulation buffer
	0, 0, 0, 0,			// accum bits (ignored)
	0,				// depth buffer (filled below)
	0,				// no stencil buffer
	0,				// no auxiliary buffers
	PFD_MAIN_PLANE,			// main layer
	0,				// reserved
	0, 0, 0,			// no layer, visible, damage masks
    };
    int SelectedPixelFormat;
    BOOL retVal;

    if (m_glOptions.doubleBuffered) {
        pfd.dwFlags |= PFD_DOUBLEBUFFER;
    }

    if (m_glOptions.depthBuffered) {
	pfd.cDepthBits = 16;
    }

    SelectedPixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (SelectedPixelFormat == 0) {
	throw "ChoosePixelFormat failed";
    }

    retVal = SetPixelFormat(hDC, SelectedPixelFormat, &pfd);
    if (retVal != TRUE) {
	MessageBox(WindowFromDC(hDC), "SetPixelFormat failed", "Error",
		MB_ICONERROR | MB_OK);
	exit(1);
    }
}







