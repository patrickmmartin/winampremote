/*
 * ServerEnumerator.h
 *
 *  Created on: 29 Jan 2012
 *      Author: Patrick
 */

#ifndef SERVERENUMERATOR_H_
#define SERVERENUMERATOR_H_

#include <windows.h>
#include <vcl.h>

/**
 * class to wrap up the task of enumerating Windows local net neighbourhood resources
 * and extracting the machine nodes from the results.
 */
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
	 * enumerates the servers on the network neighbourhood.
	 * Events will be emitted when candidates or information is found.
	 */
	void enumerateServers();

private:

	int resourcesProcessed_;
	int resourceTotal_;
	/**
	 * Lightweight debugging: outputs some debug info of an operations and a message.
	 * @param operation
	 * @param message
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
