/*
 * ServerEnumerator.h
 *
 *  Created on: 29 Jan 2012
 *      Author: Patrick
 */

#ifndef SERVERENUMERATOR_H_
#define SERVERENUMERATOR_H_

#include <vcl.h>
#pragma hdrstop

#include <windows.h>

/**
 * class to wrap up the task of enumerating Windows local net neighbourhood resources
 * and extracting the machine nodes from the results.
 */

      /**
       * Closure for the server discovery event.
       * @param remoteName
       * @param comment
       */
      typedef void (__closure *TSEServerEvent)(const AnsiString& remoteName, const AnsiString& comment);
      /**
       * Closure for a general message event.
       * @param message
       * @param Level
       */
      typedef void (__closure *TSEMessageEvent)(const AnsiString& message, const int Level);
      /**
       * Closure for the progress event.
       * @param complete
       */
      typedef void (__closure *TSEProgressEvent)(const float complete);


class ServerEnumerator {
public:
	/**
	 * constructor
	 */
	ServerEnumerator();
	/**
	 * destructor
	 */
	virtual ~ServerEnumerator();

        /**
         * notification for a server encountered
         */
	__property TSEServerEvent OnServer = {read = FServerEvent, write = FServerEvent};

	/**
	 * notification for a message event
	 */
        __property TSEMessageEvent OnMessage = {read = FMessageEvent, write = FMessageEvent};

        /**
         * notification for a progress event
         */
        __property TSEProgressEvent OnProgress = {read = FProgressEvent, write = FProgressEvent};

	/**
	 * enumerates the servers on the network neighbourhood.
	 * Events will be emitted when candidates or information is found.
	 */
	void enumerateServers();

private:

	int resourcesProcessed_;
	int resourceTotal_;

        TSEServerEvent FServerEvent;
        TSEMessageEvent FMessageEvent;
        TSEProgressEvent FProgressEvent;

	/**
	 * Lightweight debugging: outputs some debug info of an operations and a message.
	 * @param operation
	 * @param message
	 *
	 */
    void debugOutput(const AnsiString & operation, const AnsiString & message);
	/**
	 * Handles the error condition for the given net resource.
	 * @param dwErrorCode returned error code
	 * @param errorFunction the function in error
	 */
	void netErrorHandler(const DWORD dwErrorCode, const AnsiString& errorFunction);
	/**
	 * Handles display of the passed net resource.
	 * @param NetResource the net resource
	 */
	void handleResource(const NETRESOURCE& resource);
	/**
	 * Enumerate function for the net resources.
	 * @param resourcePtr the net resource
	 * @return
	 */
	BOOL enumerateFunc(const LPNETRESOURCE resourcePtr);
	/**
	 * Adds a server to the current node.
	 * @param RemoteName
	 * @param Comment
	 */
	void addServer(const AnsiString& remoteName, const AnsiString& comment);
	/**
	 * Emits a progress message.
	 * @param Message
	 * @param Level
	 */
	void addMessage(const AnsiString& message, const int Level);

	/**
	 * Updates the known enumeration progress so far.
	 * @param complete
	 */
	void updateProgress(const float complete);

};

#endif /* SERVERENUMERATOR_H_ */
