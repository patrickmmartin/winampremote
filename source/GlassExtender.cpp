/*
 * GlassExtender.cpp
 *
 *
 *  Created on: 10 Mar 2012
 *      Author: Patrick
 */

#include "GlassExtender.h"


void GlassExtender::DWMCompositionChanged(TMessage& /* Msg */)
{
	// TODO handle and notify the parent form m_Form
}

bool GlassExtender::glassWindow(TWinControl * winControl)
{
	const MARGINS margins = { -1 };
	if (!(SUCCEEDED ( m_ExtendFrameProc(winControl->Handle, &margins ) )))
		return false;
	for (int i = 0 ; i < winControl->ControlCount ; i++)
	{
		TControl * childControl = winControl->Controls[i];
		TWinControl * childWinControl = dynamic_cast<TWinControl *>(childControl);
		if ( childWinControl )
		{
		    glassWindow(childWinControl);
		    return true;
		}
	}
	return false;

}


bool GlassExtender::extendIntoClientAll()
{
	// Extend frame across entire window.
	if (NULL != m_ExtendFrameProc)
	{
		return glassWindow(m_Form);
	}
	return false;
}


bool GlassExtender::isCompositionActive()
{

  if ( (NULL != m_dwmapi) &&
       (NULL != m_DWMEnabledProc) )
    {
      BOOL enabled = FALSE;
      if ( SUCCEEDED(m_DWMEnabledProc(&enabled)) )
        return enabled;
    }
    return false;
}




/* WINDOW parts */
#define WP_CAPTION	1

/* WINDOW CAPTION / SMALLCAPTION state */
#define CS_ACTIVE   1



#define LBCP_ITEM 5

#define LBPSI_HOT 1
#define LBPSI_HOTSELECTED 2
#define LBPSI_SELECTED 3
#define LBPSI_SELECTEDNOTFOCUS 4

bool GlassExtender::drawGlowText(HDC dc, const AnsiString& item,const TRect &itemRect,
                                 bool current)
{

  if (NULL == m_DrawThemeTextExProc)
	  return false;

  if (NULL == m_OpenThemeDataProc)
	  return false;

  if (NULL == m_CloseThemeDataProc)
	  return false;

  DTTOPTS dttOpts = {0};

  RECT R = Rect(itemRect.Left, itemRect.Top, itemRect.Right, itemRect.Bottom);

  dttOpts.dwSize = sizeof(DTTOPTS);
  dttOpts.iGlowSize = 3;
  dttOpts.dwFlags = /* DTT_GLOWSIZE |*/ DTT_STATEID;
  dttOpts.crText = clGreen;
  dttOpts.dwFlags |= DTT_TEXTCOLOR;

  HANDLE hTheme = m_OpenThemeDataProc(0, L"WINDOW");

  if (current)
  {
    dttOpts.crText = clWhite;
    dttOpts.dwFlags |= DTT_TEXTCOLOR | DTT_GLOWSIZE ;
  }

  HRESULT ret = m_DrawThemeTextExProc(hTheme, dc, LBCP_ITEM, 0,
                                          WideString(item).c_bstr(), -1,
                                          DT_LEFT | DT_TOP | DT_SINGLELINE | DT_NOPREFIX,
                                          &R, &dttOpts);

  m_CloseThemeDataProc(hTheme);
  return SUCCEEDED(ret);
}


__fastcall
GlassExtender::GlassExtender(TForm * Owner) :
		TComponent(Owner),
		m_ExtendFrameProc(NULL),
		m_DWMEnabledProc(NULL),
		m_DrawThemeTextExProc(NULL),
                m_OpenThemeDataProc(NULL),
		m_uxtheme(NULL),
		m_dwmapi(NULL),
		m_Form(NULL)
{

	if (Owner)
	{
		m_Form = Owner;
		// used over the raw API call due to issues with FP mode conflicts
		m_dwmapi = ::SafeLoadLibrary(AnsiString("dwmapi.dll"), SEM_NOOPENFILEERRORBOX);
		m_uxtheme = ::SafeLoadLibrary(AnsiString("uxtheme.dll"), SEM_NOOPENFILEERRORBOX);
		if (NULL != m_uxtheme)
		{
			m_OpenThemeDataProc = (OpenThemeDataProc)
            					::GetProcAddress((HMODULE) m_uxtheme, "OpenThemeData");
			m_CloseThemeDataProc = (CloseThemeDataProc)
            					::GetProcAddress((HMODULE) m_uxtheme, "CloseThemeData");
			m_DrawThemeTextExProc = (DrawThemeTextExProc)
            					::GetProcAddress((HMODULE) m_uxtheme, "DrawThemeTextEx");

		}
		if (NULL != m_dwmapi)
		{
			m_ExtendFrameProc = (ExtendFrameProc)
                                ::GetProcAddress((HMODULE) m_dwmapi, "DwmExtendFrameIntoClientArea");
			m_DWMEnabledProc = (DWMEnabledProc)
                                ::GetProcAddress((HMODULE) m_dwmapi, "DwmIsCompositionEnabled");
			extendIntoClientAll();
			// fixups for any Glass display issues can only be done by UI classes
		}
	}

}

__fastcall
GlassExtender::~GlassExtender()
{
	if (m_dwmapi)
		::FreeLibrary( (HMODULE) m_dwmapi);
	if (m_uxtheme)
		::FreeLibrary( (HMODULE) m_uxtheme);
}

