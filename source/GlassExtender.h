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


	typedef struct _DTTOPTS {
	  DWORD             dwSize;
	  DWORD             dwFlags;
	  COLORREF          crText;
	  COLORREF          crBorder;
	  COLORREF          crShadow;
	  int               iTextShadowType;
	  POINT             ptShadowOffset;
	  int               iBorderSize;
	  int               iFontPropId;
	  int               iColorPropId;
	  int               iStateId;
	  BOOL              fApplyOverlay;
	  int               iGlowSize;
	  void * pfnDrawTextCallback; 			// AACK to avoid pulling in the world
	  LPARAM            lParam;
	} DTTOPTS, *PDTTOPTS;

/* DrawThemeText() flags */
#define DTT_TEXTCOLOR       0x00000001L
#define DTT_BORDERCOLOR     0x00000002L
#define DTT_SHADOWCOLOR     0x00000004L
#define DTT_SHADOWTYPE      0x00000008L
#define DTT_SHADOWOFFSET    0x00000010L
#define DTT_BORDERSIZE      0x00000020L
#define DTT_FONTPROP        0x00000040L
#define DTT_COLORPROP       0x00000080L
#define DTT_STATEID         0x00000100L
#define DTT_CALCRECT        0x00000200L
#define DTT_APPLYOVERLAY    0x00000400L
#define DTT_GLOWSIZE        0x00000800L
#define DTT_CALLBACK        0x00001000L
#define DTT_COMPOSITED      0x00002000L



    typedef HRESULT (__stdcall *DWMEnabledProc)(BOOL * enabled);
	typedef HRESULT (__stdcall *ExtendFrameProc)(HANDLE hWnd, const MARGINS *pMarInset);
	typedef HRESULT (__stdcall *DrawThemeTextExProc)(HANDLE hTheme,
                                                         HDC hdc,
                                                         int iPartId,
                                                         int iStateId,
                                                         LPCWSTR pszText,
                                                         int iCharCount,
                                                         DWORD dwFlags,
                                                         LPRECT pRect,
                                                         const DTTOPTS *pOptions);

        typedef HANDLE (__stdcall *OpenThemeDataProc)(HWND hwnd, LPCWSTR pszClassList);
        typedef HRESULT (__stdcall *CloseThemeDataProc)(HANDLE hTheme);


	HINST m_dwmapi;
	HINST m_uxtheme;
	ExtendFrameProc m_ExtendFrameProc;
	DWMEnabledProc m_DWMEnabledProc;
	DrawThemeTextExProc m_DrawThemeTextExProc;
    OpenThemeDataProc m_OpenThemeDataProc;
    CloseThemeDataProc m_CloseThemeDataProc;
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
        bool drawGlowText(HDC dc, const AnsiString& item,const TRect &itemRect,
                          TOwnerDrawState state, bool current);

//	BEGIN_MESSAGE_MAP
//	// handling DWM composition changes
//	MESSAGE_HANDLER(WM_DWMCOMPOSITIONCHANGED, TMessage, DWMCompositionChanged)
//	END_MESSAGE_MAP(GlassExtender)


};

#endif /* GLASSEXTENDER_H_ */
