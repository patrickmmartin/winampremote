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

    // TODO  a typedef for the remoteNoode name moniker?
      /**
       * Closure for the client supplied bind procedure, required for each test node.
       * @param node
       * @param endpoint
       */
      typedef void __fastcall (__closure *TBindEvent)(const AnsiString& node,
                                                      const AnsiString& endpoint);

      /**
       * Closure for the Server test event.
       * @param remoteName
       * @param data
       * @param level
       */
      typedef void __fastcall (__closure *TSTServerMessageEvent)(const AnsiString& remoteName,
                                                                 const AnsiString& data,
                                                                 const int level);

      /**
       * Closure for when the server result is determined.
       * @param remoteName
       * @param success
       */
      typedef void __fastcall (__closure *TSTServerResultEvent)(const AnsiString& remoteName,
                                                                const bool success);


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
         * closure for the bind event prior to testing
         */
        __property TBindEvent OnBind = {read = FBindProc, write = FBindProc};

        /**
         * notification closure for a server test result
         */
        __property TSTServerMessageEvent OnTest = {read = FServerMessageEvent, write = FServerMessageEvent};

        /**
         * notification closure for a server test result
         */
        __property TSTServerResultEvent OnResult = {read = FServerResultEvent, write = FServerResultEvent};






        /**
         * Function to accept list of servers to be tested.
         * @param servers
         */
        void testServers(const vector<string>& servers, const AnsiString& endpoint);

private:

        TSTServerMessageEvent FServerMessageEvent;
        TSTServerResultEvent FServerResultEvent;
        TBindEvent FBindProc;


        void DoMessage(const AnsiString& remoteName, const AnsiString& data, const int level);
        void DoResult(const AnsiString& remoteName, const bool success);
        void DoBind(const AnsiString& node, const AnsiString& endpoint);

};


#endif /* SERVERTESTER_H_ */
