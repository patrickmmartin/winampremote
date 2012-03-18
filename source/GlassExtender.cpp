/*
 * GlassExtender.cpp
 *
 *
 *  Created on: 10 Mar 2012
 *      Author: Patrick
 */

#include "GlassExtender.h"


void GlassExtender::DWMCompositionChanged(TMessage& Msg)
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
		// used over the raw API call due to issues with FP mode conflicts
		m_dwmapi = ::SafeLoadLibrary(AnsiString("dwmapi.dll"), SEM_NOOPENFILEERRORBOX);
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
}

