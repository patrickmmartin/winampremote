/*
 * CursorGuard.cpp
 *
 *  Created on: 24 Mar 2013
 *      Author: Patrick
 */

#include "CursorGuard.h"

namespace WinampRemote
{
namespace Utils
{

CursorGuard::CursorGuard(Controls::TCursor newCursor)
{
	m_cursor = Screen->Cursor;
	Screen->Cursor = newCursor;

}

CursorGuard::~CursorGuard()
{
	Screen->Cursor = m_cursor;
}

} /* namespace Utils */
} /* namespace WinampRemote */
