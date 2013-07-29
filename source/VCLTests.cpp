/*
 * VCLTests.cpp
 *
 *  Created on: 27 Jul 2013
 *      Author: Patrick
 */

#include "catch.hpp"

#include <forms.hpp>

#include "CursorGuard.h"
#include "ClientConfig.h"

#include <sstream.h>

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

TEST_CASE("Client/Config", "tests ClientConfig class")
{

	// create 2 instances
	WinampRemote::Config::ClientConfig config_old;
	WinampRemote::Config::ClientConfig config;

	// stream out the representations
	std::ostringstream ostr, ostr_old, ostr_new;
	ostr << config;
	ostr_old << config_old;
	// check the streams
	CHECK(ostr.str() == ostr_old.str());

	//update a value
	LONG bottom = config.PlaylistPos().Bottom;
	config.PlaylistPos().Bottom++;
	CHECK((bottom + 1) == config.PlaylistPos().Bottom);

	// check the stream changes
	ostr_new << config;
	CHECK(ostr.str() != ostr_new.str());


}

} /* namespace UnitTest */
} /* namespace WinampRemote */
