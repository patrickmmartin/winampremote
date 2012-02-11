/*
 * ServerEnumerator.cpp
 *
 *  Created on: 29 Jan 2012
 *      Author: Patrick
 */

#include "ServerEnumerator.h"
#include <vcl.h>
#include "remotestrs.h"

#include <iostream.h>

using std::cout;
using std::endl;

ServerEnumerator::ServerEnumerator() {
	// TODO Auto-generated stub

}

ServerEnumerator::~ServerEnumerator() {
	// TODO Auto-generated stub
}

void ServerEnumerator::enumerateServers() {
	// begin enumeration
	enumerateFunc(NULL);
}

void ServerEnumerator::debugOutput(const AnsiString & operation, const AnsiString & message)
{
    cout << AnsiString().sprintf("%s: [%s]", operation, message).c_str() << endl;;
}

void ServerEnumerator::addMessage(const AnsiString& message, const int level) {
    debugOutput("Message", message);
}

void ServerEnumerator::addServer(const AnsiString& remoteName, const AnsiString& comment) {
  debugOutput("Server", remoteName + "-" + comment);
}

void ServerEnumerator::updateProgress(const float complete) {
  debugOutput("Progress", AnsiString().sprintf("%.0f", complete * 100));
}

void ServerEnumerator::handleResource(const NETRESOURCE& resource) {

	if (resource.dwDisplayType == RESOURCEDISPLAYTYPE_SERVER)
	{
		AnsiString remoteName = resource.lpRemoteName;
		// TODO strip out the UNC prefix more intelligently
		remoteName.Delete(1, 2);
		addServer(remoteName, resource.lpComment);
		addMessage(AnsiString().sprintf("\tFound node %s", remoteName.c_str()), 0);
	}
}

void ServerEnumerator::netErrorHandler(const DWORD dwErrorCode, const AnsiString& errorFunction) {
	DWORD dwWNetResult, dwLastError;
	char szDescription[256];
	char szProvider[256];
	AnsiString MessageStr;
	int MessageSeverity;

	// The following code performs standard error-handling.

	if (dwErrorCode != ERROR_EXTENDED_ERROR)
	{
		// warning
		addMessage(errorFunction, 2);
		MessageStr = SysErrorMessage(dwErrorCode) + ".";
		MessageSeverity = 0;
	} else {
		dwWNetResult = WNetGetLastError(&dwLastError, (LPSTR) szDescription,
				sizeof(szDescription), (LPSTR) szProvider, sizeof(szProvider));

		if (dwWNetResult != NO_ERROR)
		{
			// error
			MessageStr = AnsiString().sprintf(
					sWNetGetLastErrorFailedFmt.c_str(), dwWNetResult);
		}
		// warning

		MessageSeverity = 3;
		MessageStr = AnsiString().sprintf(sWNetFailedFmt.c_str(), szProvider,
				dwLastError, szDescription);
	}

	// there are new lines
	StringReplace(MessageStr, "\r\n", " ", TReplaceFlags() << rfReplaceAll);

	addMessage(MessageStr, MessageSeverity);

}

BOOL ServerEnumerator::enumerateFunc(const LPNETRESOURCE lpnr) {
	DWORD dwResult, dwResultEnum;
	HANDLE hEnum;
	DWORD cbBuffer = 16384; // 16K is a good size
	DWORD cEntries = 0xFFFFFFFF; // enumerate all possible entries
	LPNETRESOURCE lpnrLocal; // pointer to enumerated structures
	DWORD i;

	// first time case
	if (lpnr == NULL)
	{
		// so far
		resourcesProcessed_ = 0;
		// the whole net
		resourceTotal_ = 1;

		addMessage(sStartEnumerateNetwork, 1);
	}

	// update
	updateProgress(((float) resourcesProcessed_ / (float) resourceTotal_));

	resourcesProcessed_++;

	dwResult = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY,

	0, // enumerate all resources
			lpnr, // NULL first time this function is called
			&hEnum); // handle to resource

	if ((dwResult != NO_ERROR )) {

		// An application-defined error handler is demonstrated in the
		// section titled "Retrieving Network Errors."

		netErrorHandler(dwResult, "WNetOpenEnum");
		return FALSE;
	}

	do {

		// Allocate memory for NETRESOURCE structures.

		lpnrLocal = (LPNETRESOURCE) GlobalAlloc(GPTR, cbBuffer);

		dwResultEnum = WNetEnumResource(hEnum, // resource handle
				&cEntries, // defined locally as 0xFFFFFFFF
				lpnrLocal, // LPNETRESOURCE
				&cbBuffer); // buffer size

		if (dwResultEnum == NO_ERROR) {
			resourceTotal_ += cEntries;
			for (i = 0; i < cEntries; i++) {
				handleResource(lpnrLocal[i]);
				// recurse if it is a container of interest
				// would like a way to avoid Terminal Services and Web Client...
				if ((RESOURCEUSAGE_CONTAINER
						== (lpnrLocal[i].dwUsage & RESOURCEUSAGE_CONTAINER))
						&& !(lpnrLocal[i].dwDisplayType
								== RESOURCEDISPLAYTYPE_SERVER)) {

					AnsiString ObjectName;

					if (lpnrLocal[i].lpRemoteName)
						ObjectName = lpnrLocal[i].lpRemoteName;
					else
						ObjectName = lpnrLocal[i].lpProvider;

					addMessage(
							AnsiString().sprintf(sEnumeratingContainer.c_str(),
									ObjectName.c_str()), 1);
					enumerateFunc(&lpnrLocal[i]);
				}
			}
		} else if (dwResultEnum != ERROR_NO_MORE_ITEMS) {
			netErrorHandler(dwResultEnum, "WNetEnumResource");
			break;
		}
		GlobalFree((HGLOBAL) lpnrLocal);
	} while (dwResultEnum != ERROR_NO_MORE_ITEMS);

	dwResult = WNetCloseEnum(hEnum);

	if (dwResult != NO_ERROR) {
		netErrorHandler(dwResult, "WNetCloseEnum");

		return FALSE;
	}

	return TRUE;
}

