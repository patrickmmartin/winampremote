/*
 * GlassExtender.cpp
 *
 *
 *  Created on: 10 Mar 2012
 *      Author: Patrick
 */

#include "GlassExtender.h"

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
		if (glassWindow(m_Form))
		{
			// TODO hook message
			// anything else?
		}
	}
	return false;
}


bool GlassExtender::isCompositionActive()
{

  if ( (NULL != m_dwmapi) &&
       (NULL != m_DWMEnabledProc) )
    {
      BOOL enabled = FALSE;
      if ( SUCCEEDED(m_DWMEnabledProc(&enabled)) &&
          enabled)
        return true;
    }
    return true;
}


__fastcall
GlassExtender::GlassExtender(TForm * Owner) :
		TComponent(Owner),
		m_ExtendFrameProc(NULL),
		m_DWMEnabledProc(NULL),
		m_dwmapi(NULL),
		m_Form(NULL)
{

	if (Owner)
	{
		m_Form = Owner;
		// due to issues with FP mode conflicts
		m_dwmapi = ::SafeLoadLibrary(AnsiString("dwmapi.dll"), SEM_NOOPENFILEERRORBOX);
		if (NULL != m_dwmapi)
		{
			m_ExtendFrameProc = (ExtendFrameProc) ::GetProcAddress((HMODULE) m_dwmapi,
																	"DwmExtendFrameIntoClientArea");
			// TODO attach to form and hook window procedure
			extendIntoClientAll();
			// TODO fixups for any Glass display issues
		}
	}

}

__fastcall
GlassExtender::~GlassExtender()
{
	if (m_dwmapi)
		::FreeLibrary( (HMODULE) m_dwmapi);
}

