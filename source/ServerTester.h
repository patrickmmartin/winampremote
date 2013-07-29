/*
 * ServerTester.h
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#ifndef SERVERTESTER_H_
#define SERVERTESTER_H_

#include <system.hpp>
#pragma hdrstop

#include <map.h>

enum ServerStatus
{
	SI_UNTESTED, SI_FAILED, SI_SUCCESS
};


struct ServerInfo
{
	AnsiString comment;
	ServerStatus status;

	ServerInfo(): comment(""), status(SI_UNTESTED) {};
};



/**
 * class to wrap up the task of testing servers for a running Winamp server.
 */


class ServerTester {
public:
        /**
         * constructor
         */
        ServerTester();
        /**
         * destructor
         */
        virtual ~ServerTester();

        /**
         * property for the endpoint to be tested
         */
        __property AnsiString endPoint = {read = _endPoint, write = _endPoint};

        /**
         * Function to accept list of servers to be tested.
         * @param servers map of names -> server info
         */
        void testServers(std::map<AnsiString, ServerInfo>& servers);

        /**
         * Function to accept a server to be tested for a response
         * @param remote - machine name to test
         * @param serverInfo server info to be populated
         */
        void testServer(const AnsiString& remote, ServerInfo& serverInfo);

private:

        AnsiString _endPoint;
        bool _abort;

        void DoMessage(const AnsiString& remoteName, const AnsiString& data, const int level);
        void DoResult(const AnsiString& remoteName, const bool success);

};


#endif /* SERVERTESTER_H_ */
