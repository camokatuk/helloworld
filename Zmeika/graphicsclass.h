#pragma once

/* 
The graphics class is the other object that is created by the system class.
All the graphics functionality in this application will be encapsulated in this class.
I will also use the header in this file for all the graphics related global settings that we may want to change such as full screen or windowed mode.
Currently this class will be empty but in future tutorials will contain all the graphics objects.
*/

#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

#include <windows.h>

#include "d3dclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();
	D3DClass* m_Direct3D;

private:

};

#endif

