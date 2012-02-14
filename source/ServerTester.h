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

#include <vector.h>

/**
 * class to wrap up the task of testing servers for a running Winamp server.
 */

    // TODO  a typedef for the remoteNode name moniker?
      /**
       * Closure for the Server test event.
       * @param remoteName
       * @param data
       * @param level
       */
      typedef void (__closure *TSTServerMessageEvent)(const AnsiString& remoteName,
                                                                 const AnsiString& data,
                                                                 const int level);

      /**
       * Closure for when the server result is determined.
       * @param remoteName
       * @param success
       * @param abort
       */
      typedef void (__closure *TSTServerResultEvent)(const AnsiString& remoteName,
                                                                const bool success,
                                                                bool& abort);


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
         * notification closure for a server test result
         */
        __property TSTServerMessageEvent OnTest = {read = _serverMessageEvent, write = _serverMessageEvent};

        /**
         * notification closure for a server test result
         */
        __property TSTServerResultEvent OnResult = {read = _serverResultEvent, write = _serverResultEvent};

        /**
         * property for the endpoint to be tested
         */
        __property AnsiString endPoint = {read = _endPoint, write = _endPoint};

        /**
         * Function to accept list of servers to be tested.
         * @param servers
         */
        void testServers(vector<AnsiString>& servers);

private:

        bool  _abort;
        AnsiString _endPoint;
        TSTServerMessageEvent _serverMessageEvent;
        TSTServerResultEvent _serverResultEvent;


        void DoMessage(const AnsiString& remoteName, const AnsiString& data, const int level);
        void DoResult(const AnsiString& remoteName, const bool success);

};


#endif /* SERVERTESTER_H_ */
