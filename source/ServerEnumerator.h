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
 * class to wrap up the enumerating Windows local net neighbourhood resources
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
	 * enumerates the servers on the network neighbourhood
	 */
	void enumerateServers();

private:

        int ResourcesEnumerated;
        int ResourcesToEnumerate;
	/**
	 * Handles the error condition for the given net resource.
	 * @param dwErrorCode
	 * @param Function
	 */
	void NetErrorHandler(const DWORD dwErrorCode, const AnsiString& Function);
	/**
	 * Handles display of the passed net resource.
	 * @param NetResource
	 */
	void HandleResource(const NETRESOURCE& NetResource);
	/**
	 * Enumerate function for the net resources.
	 * @param lpnr
	 * @return
	 */
	BOOL EnumerateFunc(const LPNETRESOURCE lpnr);
	/**
	 * Adds a server to the current node.
	 * @param RemoteName
	 * @param Comment
	 */
	void AddServer(const AnsiString& RemoteName, const AnsiString& Comment);
	/**
	 * Adds a progress message.
	 * @param Message
	 * @param Level
	 */
	void AddMessage(const AnsiString& Message, const int Level);

	/**
	 * Updates the known enumeration progress so far.
	 * @param complete
	 */
	void UpdateProgress(const float complete);

};

#endif /* SERVERENUMERATOR_H_ */
