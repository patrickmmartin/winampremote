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
#include <messages.hpp>
#pragma hdrstop


const int WM_DWMCOMPOSITIONCHANGED = 0x031E;


/**
 * Class to encapsulate handling extending Glass on Aero into the entire window frame
 */
class GlassExtender: public Classes::TComponent
{

private:

	typedef struct _MARGINS
	{
		int cxLeftWidth;
		int cxRightWidth;
		int cyTopHeight;
		int cyBottomHeight;
	} MARGINS, *PMARGINS;

    typedef HRESULT (__stdcall *DWMEnabledProc)(BOOL * enabled);
	typedef HRESULT (__stdcall *ExtendFrameProc)(HANDLE hWnd, const MARGINS *pMarInset);

	HINST m_dwmapi;
	ExtendFrameProc m_ExtendFrameProc;
	DWMEnabledProc m_DWMEnabledProc;
	TForm * m_Form;
	bool glassWindow(TWinControl * winControl);
	bool extendIntoClientAll();
	void DWMCompositionChanged(TMessage& Msg);

public:
	/**
	 * Constructor - can only be constructed on a TForm instance.
	 * Loads dwmapi dynamically
	 * @param AOwner
	 */
	__fastcall virtual GlassExtender(TForm* AOwner);
	/**
	 * Destructor - unloads dwmapi
	 */
	__fastcall virtual ~GlassExtender(void);
        bool isCompositionActive();

//	BEGIN_MESSAGE_MAP
//	// handling DWM composition changes
//	MESSAGE_HANDLER(WM_DWMCOMPOSITIONCHANGED, TMessage, DWMCompositionChanged)
//	END_MESSAGE_MAP(GlassExtender)


};

#endif /* GLASSEXTENDER_H_ */
