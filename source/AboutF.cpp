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



#include <vcl.h>
#pragma hdrstop

#include <GL\gl.h>
#include <GL\glu.h>
#include <math.h>
#include "AboutF.h"


#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmAbout *frmAbout;
TStringList *OutText, *CharsText;


HDC hDC;

DWORD startup;
DWORD lastdraw;
DWORD nowdraw;

#define GLF_START_LIST 20000
#define TORUS 1
#define CUBE 2
#define SPHERE 3

GLfloat textExtrusion = 0.2;

GLYPHMETRICSFLOAT glyphMetrics[127];


void TfrmAbout::resize(void)
{
     m_aboutDisplay->setClientArea(ClientWidth, ClientHeight);
     m_aboutDisplay->setProjection();
    glViewport(0, 0, TheControl->ClientWidth, TheControl->ClientHeight);
}

void TfrmAbout::redraw(void)
{
  m_aboutDisplay->redraw();
}



__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
    : TForm(Owner)

{
}


void __fastcall TfrmAbout::WMPaletteChanged(TMessage& Msg)
{

	if (hPalette != NULL && (HWND) Msg.WParam != Handle) {
	    UnrealizeObject(hPalette);
	    SelectPalette(hDC, hPalette, FALSE);
	    RealizePalette(hDC);
	    redraw();
  }

}


void __fastcall TfrmAbout::WMQueryNewPalette(TMessage& /* Msg */)
{

  if (hPalette != NULL) {
      UnrealizeObject(hPalette);
      SelectPalette(hDC, hPalette, FALSE);
      RealizePalette(hDC);
      redraw();
  }

}


void __fastcall TfrmAbout::FormCreate(TObject *)
{
    hDC = GetDC(TheControl->Handle);
    m_aboutDisplay = NULL;
    m_aboutDisplay = (new AboutGLDisplay(hDC, TheControl->ClientWidth, TheControl->ClientHeight));

    OutText = new TStringList();

}


void __fastcall TfrmAbout::FormDestroy(TObject *)
{
  ReleaseDC(TheControl->Handle, hDC);
  delete m_aboutDisplay;
  delete OutText;
//
}


void __fastcall TfrmAbout::FormMouseDown(TObject *, TMouseButton , TShiftState , int X, int Y)
{
    SetCapture(TheControl->Handle);
    m_aboutDisplay->startMotion(0, 1, X, Y);
}


void __fastcall TfrmAbout::FormMouseMove(TObject *, TShiftState , int X, int Y)
{
    m_aboutDisplay->trackMotion(0, X, Y);
}


void __fastcall TfrmAbout::FormMouseUp(TObject *, TMouseButton , TShiftState , int X, int Y)
{
    m_aboutDisplay->stopMotion(0, 1, X, Y);
}


void __fastcall TfrmAbout::FormPaint(TObject *)
{
  PAINTSTRUCT ps;
  BeginPaint(TheControl->Handle, &ps);
  redraw();
  EndPaint(TheControl->Handle, &ps);
}


void __fastcall TfrmAbout::FormResize(TObject *)
{
  resize();
//
}



void __fastcall TfrmAbout::FormKeyPress(TObject *, char &Key)
{

  AboutGLDisplay::GLOptions & gloptions = m_aboutDisplay->gloptions();
  
  switch (Key) {
  case VK_ESCAPE:
      Close();
      return;
//  case VK_SPACE:
//      gloptions.objectIndex = (gloptions.objectIndex + 1) % 4;
//      return;
  case 'a':
      gloptions.useVertexArray = !gloptions.useVertexArray;
      return;
  case 'c':
      gloptions.useFaceCull = !gloptions.useFaceCull;
      return;
  case 'f':
      gloptions.useFog = !gloptions.useFog;
      return;
  case 'h':
      gloptions.halfObject = !gloptions.halfObject;
      return;
  case 'l':
      gloptions.useLighting = !gloptions.useLighting;
      return;
  case 'o':
      gloptions.perspectiveProj = !gloptions.perspectiveProj;
      resize();
      return;
  case 'p':
      gloptions.drawOutlines = !gloptions.drawOutlines;
      return;
  case 'v':
      gloptions.useVertexCull = !gloptions.useVertexCull;
      return;
  case 'i':
      m_aboutDisplay->yOffset += AboutGLDisplay::Y_OFFSET_STEP;
      return;
  case 'j':
      m_aboutDisplay->xOffset -= AboutGLDisplay::X_OFFSET_STEP;
      return;
  case 'k':
      m_aboutDisplay->xOffset += AboutGLDisplay::X_OFFSET_STEP;
      return;
  case 'm':
      m_aboutDisplay->yOffset -= AboutGLDisplay::Y_OFFSET_STEP;
      return;
  case 'r':
      gloptions.textureReplace = !gloptions.textureReplace;
      return;
  case 't':
      gloptions.textureEnabled = !gloptions.textureEnabled;
      return;
  case 'x':
      gloptions.useVertexLocking = !gloptions.useVertexLocking;
      return;
  default:
      break;
  }


}


void __fastcall TfrmAbout::FormKeyDown(TObject *, WORD &Key, TShiftState )
{
  switch (Key) {
  /*
  case VK_DOWN:
  if (objectNumMajor > 1)
    --objectNumMajor;
      break;
  case VK_UP:
      ++objectNumMajor;
      break;
  case VK_LEFT:
  if (objectNumMinor > 1)
    --objectNumMinor;
      break;
  case VK_RIGHT:
    ++objectNumMinor;
      break;
  default:
      break;
      */
  }
  redraw();
  return;
}


void __fastcall TfrmAbout::IdleHandler(TObject *)
{
   redraw();
}

void __fastcall TfrmAbout::FormShow(TObject *)
{
  tmrMain->Enabled = true;

}


