/*
 * AboutGLDisplay.h
 *
 *  Created on: 6 Jul 2013
 *      Author: Patrick
 */

#ifndef ABOUTGLDISPLAY_H_
#define ABOUTGLDISPLAY_H_

#include <vector>
#include <string>

#include <windows.h>
#include <GL\gl.h>

class AboutGLDisplay
{

	public:
	struct GLOptions
	{

		bool halfObject;
		bool doubleBuffered;
		bool depthBuffered;
		bool drawOutlines;
		bool textureEnabled;
		bool textureReplace;
		bool useVertexCull;
		bool useFaceCull;
		bool useVertexArray;
		bool useVertexLocking;
		bool useLighting;
		bool perspectiveProj;
		bool useFog;
		GLfloat textExtrusion;

		GLOptions() :
				halfObject(false), doubleBuffered(true), depthBuffered(true), drawOutlines(
						false), textureEnabled(false), textureReplace(true), useVertexCull(
						true), useFaceCull(true), useVertexArray(true), useVertexLocking(
						true), useLighting(true), perspectiveProj(true), useFog(
						true), textExtrusion(0.2)
		{
		}
		;

	};

private:

	GLOptions m_glOptions;
	GLYPHMETRICSFLOAT glyphMetrics[127];

	std::vector<std::string> outText;

	HDC hDC;
	HGLRC hGLRC;
	int clientWidth, clientHeight;

	float angle, axis[3];

	int objectIndex;

	int objectNumMajor, objectNumMinor;

// these functions implement a simple trackball-like motion control
	bool trackingMotion;
	float lastPos[3];


	int startX, startY;

// various options

	enum MoveModes
	{
		MoveNone, MoveObject
	};

	GLfloat objectXform[4][4];

	MoveModes mode;

	DWORD startup;
	DWORD lastdraw;
	DWORD nowdraw;

public:

	void CreateFontList();
	void CreateDisplayLists();
	void drawText();
	void drawCube();
	void drawTorus();
	void drawSphere();
	void setCheckTexture();
	void setProjection();
	void setMaterial();
	void init();
	void resize();
	void doRedraw();
	void redraw();
	void ptov(int x, int y, int width, int height, float v[3]);
	void startMotion(DWORD time, int button, int x, int y);
	void stopMotion(DWORD time, int button, int x, int y);
	void trackMotion(DWORD time, int x, int y);
	void setupPalette();
	void setupPixelformat();
        void setClientArea(int clientWidth_, int clientHeight_);
	GLOptions & gloptions();
	GLfloat xOffset, yOffset;
        static const GLfloat X_OFFSET_STEP;
        static const GLfloat Y_OFFSET_STEP;

public:
	AboutGLDisplay(HDC hDC_, int clientWidth_, int clientHeight_);
	virtual ~AboutGLDisplay();
};

#endif /* ABOUTGLDISPLAY_H_ */
