/*
 * AboutGLDisplay.h
 *
 *  Created on: 6 Jul 2013
 *      Author: Patrick
 */

#ifndef ABOUTGLDISPLAY_H_
#define ABOUTGLDISPLAY_H_

#include <vector.h>
#include <string.h>

#include <windows.h>
#include <GL\gl.h>

class AboutGLDisplay
{

public:
	/**
	 * a class to wrap up the display options
	 */
	struct GLOptions
	{

		/**
		 * half object option
		 */
		bool halfObject;
		/**
		 * double buffering
		 */
		bool doubleBuffered;
		/**
		 * buffer depth
		 */
		bool depthBuffered;
		/**
		 * draw outlines
		 */
		bool drawOutlines;
		/**
		 * enable textures
		 */
		bool textureEnabled;
		/**
		 * replace textures
		 */
		bool textureReplace;
		/**
		 * use vertex culling
		 */
		bool useVertexCull;
		/**
		 * use face culling
		 */
		bool useFaceCull;
		/**
		 * use vertex arrays
		 */
		bool useVertexArray;
		/**
		 * use vertex locking
		 */
		bool useVertexLocking;
		/**
		 * use lighting
		 */
		bool useLighting;
		/**
		 * use persepective
		 */
		bool perspectiveProj;
		/**
		 * use fog
		 */
		bool useFog;
		/**
		 * text depth
		 */
		GLfloat textExtrusion;

		/**
		 * default constructor - initialises the defaults
		 */
		GLOptions() :
				halfObject(false), doubleBuffered(true), depthBuffered(true), drawOutlines(
						false), textureEnabled(false), textureReplace(true), useVertexCull(
						true), useFaceCull(true), useVertexArray(true), useVertexLocking(
						true), useLighting(true), perspectiveProj(true), useFog(
						true), textExtrusion(0.2)
		{
		};

	};

private:

	/**
	 * the options object
	 */
	GLOptions m_glOptions;
	/**
	 * the generated Glyph metrics for ASCII
	 */
	GLYPHMETRICSFLOAT glyphMetrics[127];

	/**
	 * the output text
	 */
	std::vector<std::string> outText;

	/**
	 * the device context to the painted into
	 */
	HDC hDC;
	/**
	 * the GL device context
	 */
	HGLRC hGLRC;

	// TODO - it should be possible to obtain the client area from the DC - GetDCOrgEx ? this would reduce coupling
	/**
	 * the client Width
	 */
	int clientWidth;
	/**
	 * the client height
	 */
	int clientHeight;

	/**
	 * current view angle
	 */
	float angle;
	/**
	 * current axis rotation
	 */
	float axis[3];

	/**
	 * current object to view
	 */
	int objectIndex;

	/**
	 * number of strips
	 */
	int objectNumMajor;
	/**
	 * number of partitions per strip
	 */
	int objectNumMinor;

	/**
	 * whether mouse motion tracking is on
	 */
	bool trackingMotion;

	/**
	 * last position
	 */
	float lastPos[3];

	/**
	 * start x co-ordinate of the mouse move
	 */
	int startX;
	/**
	 * start y co-ordinate of the mouse move
	 */
	int startY;

	/**
	 * different move types
	 */
	enum MoveModes
	{
		MoveNone, MoveObject
	};

	GLfloat objectXform[4][4];

	/**
	 * current move mode
	 */
	MoveModes mode;

	/**
	 * start time for the rendering
	 */
	DWORD startup;


	void CreateFontList();
	void CreateDisplayLists();
	void drawText() const;
	void drawCube() const;
	void drawTorus() const;
	void drawSphere() const;
	void setCheckTexture() const;
	void setMaterial() const;
	void init();
	void resize() const;
	void ptov(int x, int y, int width, int height, float v[3]);
	void setupPalette() const;
	void setupPixelformat() const;


public:

	/**
	 * returns the GL options in force for the next repaint
	 * @return reference to the options
	 */
	GLOptions & gloptions();
	/**
	 * X offset for the viewport
	 */
	GLfloat xOffset;
	/**
	 * Y offset for the viewport
	 */
	GLfloat yOffset;
	/**
	 * X offset step for adjustment
	 */
	static const GLfloat X_OFFSET_STEP;
	/**
	 * Y offset step for adjustment
	 */
	static const GLfloat Y_OFFSET_STEP;

	/**
	 * re-asserts the projection - use when the size or projection desired is updated
	 */
	void setProjection() const;
	/**
	 * sets the client area - clients use when this has changed
	 * @param clientWidth_
	 * @param clientHeight_
	 */
	void setClientArea(int clientWidth_, int clientHeight_);

	/**
	 * draws the current scene
	 */
	void redraw() const;

	/**
	 * starts a mouse move
	 * @param time
	 * @param button
	 * @param x
	 * @param y
	 */
	void startMotion(DWORD time, int button, int x, int y);
	/**
	 * ends a mouse move
	 * @param time
	 * @param button
	 * @param x
	 * @param y
	 */
	void stopMotion(DWORD time, int button, int x, int y);
	/**
	 * invoke for mouse tracking
	 * @param time
	 * @param x
	 * @param y
	 */
	void trackMotion(DWORD time, int x, int y);

public:
	/**
	 * constructs the About GL display class on a given DC, with client area
	 * @param hDC_
	 * @param clientWidth_
	 * @param clientHeight_
	 */
	AboutGLDisplay(HDC hDC_, int clientWidth_, int clientHeight_);
	virtual ~AboutGLDisplay();
};

#endif /* ABOUTGLDISPLAY_H_ */
