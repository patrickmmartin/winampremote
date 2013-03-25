/*
 * CursorGuard.h
 *
 *  Created on: 24 Mar 2013
 *      Author: Patrick
 */

#ifndef CURSORGUARD_H_
#define CURSORGUARD_H_

#include <forms.hpp>

namespace WinampRemote
{
namespace Utils
{

class CursorGuard
{

private:
	Controls::TCursor m_cursor;

public:
	CursorGuard(Controls::TCursor newCursor = crHourGlass);
	virtual ~CursorGuard();
};

} /* namespace Utils */
} /* namespace WinampRemote */
#endif /* CURSORGUARD_H_ */
