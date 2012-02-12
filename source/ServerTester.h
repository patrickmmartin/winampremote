/*
 * ServerTester.h
 *
 *  Created on: 12 Feb 2012
 *      Author: Patrick
 */

#ifndef SERVERTESTER_H_
#define SERVERTESTER_H_

#include <vcl.h>
#pragma hdrstop

/**
 * class to wrap up the task of testing servers for a running Winamp server.
 */

      typedef void __fastcall (__closure *TSTServerEvent)(const AnsiString& remoteName, const AnsiString& result);



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
         * notification for a server test result
         */
        __property TSTServerEvent OnTest = {read = FServerEvent, write = FServerEvent};

        void testServers();

private:

        TSTServerEvent FServerEvent;

};


#endif /* SERVERTESTER_H_ */
