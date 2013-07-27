/*
 * VCLTests.cpp
 *
 *  Created on: 27 Jul 2013
 *      Author: Patrick
 */

#include "catch.hpp"

#include <forms.hpp>

#include "CursorGuard.h"

namespace WinampRemote
{
namespace UnitTest
{


TEST_CASE("UI/CursorGuard", "tests Cursor Guard class")
{
        Controls::TCursor startCursor = Screen->Cursor;
        {
                WinampRemote::Utils::CursorGuard ci;
                CHECK(Screen->Cursor == crHourGlass);
        }
        CHECK(Screen->Cursor == startCursor);

        {
                WinampRemote::Utils::CursorGuard ci(crAppStart);
                CHECK(Screen->Cursor == crAppStart);
        }
        CHECK(Screen->Cursor == startCursor);
}


} /* namespace UnitTest */
} /* namespace WinampRemote */
