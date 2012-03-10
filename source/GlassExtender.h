/*
 * GlassExtender.h
 *
 *  Created on: 10 Mar 2012
 *      Author: Patrick
 */

#ifndef GLASSEXTENDER_H_
#define GLASSEXTENDER_H_

#include <classes.hpp>
#include <forms.hpp>
#include <windows.h>

/*
 need to handle

 WM_DWMCOMPOSITIONCHANGED message*

 in order to re-assert the glass extension
 */

/**
 * Class to encapsulate handling extending Glass on Aero into the entire window frame
 */
class GlassExtender: public Classes::TComponent
{

private:

	// TODO : check for the SDK packing values required?
	typedef struct _MARGINS
	{
		int cxLeftWidth;
		int cxRightWidth;
		int cyTopHeight;
		int cyBottomHeight;
	} MARGINS, *PMARGINS;

	typedef HRESULT (*ExtendFrameProc)(HANDLE hWnd, const MARGINS *pMarInset);

	HINST m_dwmapi;
	ExtendFrameProc m_ExtendFrameProc;
	TForm * m_Form;
	bool glassWindow(TWinControl * winControl);
	bool extendIntoClientAll();

public:
	__fastcall
	virtual GlassExtender(TForm* AOwner);__fastcall
	virtual ~GlassExtender(void);
};

#endif /* GLASSEXTENDER_H_ */
