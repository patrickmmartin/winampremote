/*
 * ServerEnumerator.cpp
 *
 *  Created on: 29 Jan 2012
 *      Author: Patrick
 */

#include "ServerEnumerator.h"
#include <vcl.h>
#include "remotestrs.h"

ServerEnumerator::ServerEnumerator() {
	// TODO Auto-generated constructor stub

}

ServerEnumerator::~ServerEnumerator() {
	// TODO Auto-generated destructor stub
}

void ServerEnumerator::AddMessage(const AnsiString& Message, const int Level)
{
	// TODO need to implement passing through message

}


void ServerEnumerator::AddServer(const AnsiString& RemoteName, const AnsiString& Comment)
{
	// TODO need to implement passing through message
}


void ServerEnumerator::UpdateProgress(const float complete)
{
        // TODO need to implement passing through completeness
}

void ServerEnumerator::HandleResource(const NETRESOURCE& NetResource)
{

  if (NetResource.dwDisplayType == RESOURCEDISPLAYTYPE_SERVER)
  {
    AnsiString RemoteName = NetResource.lpRemoteName;
    // strip out the UNC prefix
    RemoteName.Delete(1, 2);
    AddServer(RemoteName.c_str(), NetResource.lpComment);
    AddMessage(AnsiString().sprintf("\tFound node %s", RemoteName.c_str()), 0);
  }
}


void ServerEnumerator::NetErrorHandler(const DWORD dwErrorCode, const AnsiString& Function)
{
    DWORD dwWNetResult, dwLastError;
    char szDescription[256];
    char szProvider[256];
    AnsiString MessageStr;
    int MessageSeverity;

    // The following code performs standard error-handling.

    if (dwErrorCode != ERROR_EXTENDED_ERROR)
    {
        // warning
        AddMessage(Function, 2);
        MessageStr = SysErrorMessage(dwErrorCode) + ".";
        MessageSeverity = 0;
    }
    else
    {
        dwWNetResult = WNetGetLastError(&dwLastError,
            (LPSTR) szDescription,  sizeof(szDescription),
            (LPSTR) szProvider,   sizeof(szProvider));

        if(dwWNetResult != NO_ERROR)
        {
           // error
          MessageStr = AnsiString().sprintf(sWNetGetLastErrorFailedFmt.c_str(), dwWNetResult);
        }
      // warning

      MessageSeverity = 3;
      MessageStr = AnsiString().sprintf(sWNetFailedFmt.c_str(), szProvider, dwLastError, szDescription);
    }

  int Index = MessageStr.Pos("\r\n");
  while (Index > 0)
  {
    MessageStr.Delete(Index, 2);
    MessageStr.Insert(" ", Index);
    Index = MessageStr.Pos("\r\n");
  }

  AddMessage(MessageStr, MessageSeverity);

}


BOOL ServerEnumerator::EnumerateFunc(const LPNETRESOURCE lpnr)
{
    DWORD dwResult, dwResultEnum;
    HANDLE hEnum;
    DWORD cbBuffer = 16384;      // 16K is a good size
    DWORD cEntries = 0xFFFFFFFF; // enumerate all possible entries
    LPNETRESOURCE lpnrLocal;     // pointer to enumerated structures
    DWORD i;

   // first time
   if (lpnr == NULL)
   {
     // so far
     ResourcesEnumerated = 0;
     // the whole net
     ResourcesToEnumerate = 1;
     // TODO: why is the Eclipse CDT iffy about this?
     AddMessage(sStartEnumerateNetwork, 1);
   }

   // update
   UpdateProgress( ((float) ResourcesEnumerated / (float) ResourcesToEnumerate) );

   ResourcesEnumerated++;

    dwResult = WNetOpenEnum(RESOURCE_GLOBALNET,
        RESOURCETYPE_ANY,

        0,                 // enumerate all resources
        lpnr,              // NULL first time this function is called
        &hEnum);           // handle to resource

    if ( (dwResult != NO_ERROR )) {

        // An application-defined error handler is demonstrated in the
        // section titled "Retrieving Network Errors."

        NetErrorHandler(dwResult, (LPSTR)"WNetOpenEnum");
        return FALSE;
    }

    do {

        // Allocate memory for NETRESOURCE structures.

        lpnrLocal = (LPNETRESOURCE) GlobalAlloc(GPTR, cbBuffer);

        dwResultEnum = WNetEnumResource(hEnum, // resource handle
            &cEntries,               // defined locally as 0xFFFFFFFF
            lpnrLocal,               // LPNETRESOURCE
            &cbBuffer);              // buffer size

        if (dwResultEnum == NO_ERROR) {
            ResourcesToEnumerate += cEntries;
            for(i = 0; i < cEntries; i++)
            {
               HandleResource(lpnrLocal[i]);
               // recurse if it is a container of interest
               // would like a way to avoid Terminal Services and Web Client...
               if ( (RESOURCEUSAGE_CONTAINER == (lpnrLocal[i].dwUsage & RESOURCEUSAGE_CONTAINER))
                      && !(lpnrLocal[i].dwDisplayType == RESOURCEDISPLAYTYPE_SERVER) )
               {

                AnsiString ObjectName;

                if (lpnrLocal[i].lpRemoteName)
                  ObjectName = lpnrLocal[i].lpRemoteName;
                else
                  ObjectName = lpnrLocal[i].lpProvider;

                AddMessage(AnsiString().sprintf(sEnumeratingContainer.c_str(),
                                                ObjectName.c_str()),
                                                1);
                EnumerateFunc(&lpnrLocal[i]);
            }
          }
        }
        else if (dwResultEnum != ERROR_NO_MORE_ITEMS) {
            NetErrorHandler(dwResultEnum, (LPSTR)"WNetEnumResource");
            break;
        }
      GlobalFree((HGLOBAL) lpnrLocal);
    }
    while(dwResultEnum != ERROR_NO_MORE_ITEMS);


    dwResult = WNetCloseEnum(hEnum);

    if(dwResult != NO_ERROR) {
        NetErrorHandler(dwResult, (LPSTR)"WNetCloseEnum");

        return FALSE;
    }

    return TRUE;
}

