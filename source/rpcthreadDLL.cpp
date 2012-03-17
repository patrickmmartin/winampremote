/*
winamp remote control suite ©Patrick Michael Martin 2000, 2001, 2002

Copyright (C) 2000,2001,2002  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/

#include <vcl.h>
#pragma hdrstop
#include <malloc.h>
#include <stdio.h>

#include "rpcthreadDLL.h"
#pragma package(smart_init)

// winamp interface definitions
#include "waint.h"

// RPC function definitions
#include "RPCFuncsU.h"


TRTLCriticalSection fCriticalSection ;

// here follow the previously prototyped functions implemented

/* note that the use of const for "in-only" strings
 seems to break the ability to match the function signature, and leads to linker errors*/

/* __RPC_FAR is literally nothing, but is left in for consistency
- none of the MIDL generated code should need direct modification*/

void WAMessageProc(
    /* [string][out][in] */ unsigned char __RPC_FAR *pszString)
{
  try
  {            // test for C++ exceptions
    try
    {         // test for C-based structured exceptions
      // functions to be protected in here
      MainIdent((char *) pszString);
      AnsiString str = (char *) pszString;
      str += " sent hello";
      MainMessage(str.c_str());
      MainStatus(waListening);
    }
   __except(1)
    {
      /* specify actions to take for this structured exception */
      throw(Exception("structured exception generated in WAMessageProc()"));
    }
  }
  catch ( Exception &E )
  {
    // handler for any C++ exception
    OutputDebugString(E.Message.c_str());
    if (frmMain->requestlog[EXCEPTIONS])
    {
      MainMessage(strdup(E.Message.c_str()));
    }
  }
}


void WAExecuteMessage(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command)
{
const char * commandStr;

  try
  {            // test for C++ exceptions
    try
    {         // test for C-based structured exceptions
      MainIdent((char *) pszString);
      if (frmMain->requestlog[COMMAND_INTEGER])
      {
        AnsiString str = (char *) pszString;
        str += " sent  - command : ";

        commandStr = WinampCommandDesc(command);
        if (commandStr)
          str += commandStr;
        else
          str += command;

        MainMessage( str.c_str());
      }
      ExecuteMessage(command);
      MainStatus(waListening);
    }
    __except(1)
    {
      throw(Exception(AnsiString("structured exception generated in WAExecuteMessage() : " + SysErrorMessage(RpcExceptionCode()))));
    }
  }
  catch ( Exception &E )
  {
    OutputDebugString(E.Message.c_str());
    if (frmMain->requestlog[EXCEPTIONS])
    {
      MainMessage(strdup(E.Message.c_str()));
    }
  }
}


void WAExecuteMessageString(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [string][in] */ unsigned char __RPC_FAR *pszParam,
    /* [in] */ long command)
{

const char * commandStr;

  try
  {            // test for C++ exceptions
    try
    {         // test for C-based structured exceptions
      MainIdent((char *) pszString);
      if (frmMain->requestlog[COMMAND_STRING])
      {

        AnsiString str = (char *) pszString;
        str += " sent  - command : ";

        commandStr = WinampCommandDesc(command);
        if (commandStr)
          str += commandStr;
        else
          str += command;

          str += " - parameter : ";
          str += (char *) pszParam;
          MainMessage( str.c_str());
      }

      ExecuteStringMessage( (char *) pszParam, command);
      MainStatus(waListening);
    }
    __except(1)
    {
      throw(Exception(AnsiString("structured exception generated in WAMessageString() : " + SysErrorMessage(RpcExceptionCode()))));
    }
  }
  catch ( Exception &E )
  {
    // handler for any C++ exception
    OutputDebugString(E.Message.c_str());
    if (frmMain->requestlog[EXCEPTIONS])
    {
      MainMessage(strdup(E.Message.c_str()));
    }
  }
}

long WAIntegerResult(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    long command,
    long data)
{

const char * commandStr;
int result;
  try
  {            // test for C++ exceptions
    try
    {         // test for C-based structured exceptions
      MainIdent((char *) pszString);
      if (frmMain->requestlog[QUERY_INTEGER])
      {
        AnsiString str = (char *) pszString;
        str += " sent  - command : ";
        commandStr = WinampCommandDesc(command);
        if (commandStr)
          str += commandStr;
        else
          str += command;

        str += " - data : ";
        str += data;
        MainMessage( str.c_str());
      }
      //execute command
      result = GetAmpInt(command, data);
      MainStatus(waListening);
      return result;

    }
    __except(1)
    {
      throw (Exception(AnsiString("structured exception generated in WAIntegerResult() : " + SysErrorMessage(RpcExceptionCode()))));
    }
  }
  catch ( Exception &E )
  {
    OutputDebugString(E.Message.c_str());
    if (frmMain->requestlog[EXCEPTIONS]){
      MainMessage(strdup(E.Message.c_str()));
    }
  }

 return 0;
}

long int WAStringResult(
    /* [size_is][string][out][in] */ unsigned char __RPC_FAR *pszString,
    long command,
    long data)
{
  char * retval;
  const char * commandStr;
  AnsiString str;

  EnterCriticalSection(&fCriticalSection);
  try
  {
     try
     {            // test for C++ exceptions
        try
        {         // test for C-based structured exceptions
          MainIdent((char *) pszString);
          MainStatus(waListening);

          retval = GetAmpStr(command, data);

          if (frmMain->requestlog[QUERY_STRING])
          {
            str = (char *) pszString;
            str += " sent  - command : ";

            commandStr = WinampCommandDesc(command);
            if (commandStr)
              str += commandStr;
            else
              str += command;

            str += " - data : ";
            str += data;

            MainMessage( str.c_str());

            str = retval;
            str += " returned";

            MainMessage (str.c_str());
          }


          if (retval)
          {
            strcpy((char *) pszString, retval);
          }
          else
          {
            sprintf((char *) pszString,  "command %d data %d returned null", command, data);
          }  
        }

        __except(1)
        {
          throw(Exception(AnsiString("structured exception generated in WAStringResult() : " + SysErrorMessage(RpcExceptionCode()))));
        }
     }
     catch ( Exception &E )
     {
       OutputDebugString(E.Message.c_str());
        if (frmMain->requestlog[EXCEPTIONS])
        {
          MainMessage(strdup(E.Message.c_str()));
        }
      }
    }
   __finally
  {
   LeaveCriticalSection(&fCriticalSection);
  }
  return 0;

}


void WAShutdown(void)
{

RPC_STATUS status;

  MainMessage("rpc thread asked to stop");
  status = RpcMgmtStopServerListening(NULL);
  if (status == RPC_S_OK)
  {
    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    if (status == RPC_S_OK)
    {
      MainMessage("interface unregistered");
      MainStatus(waServerStopped);
    }
    else
    {
      MainMessage("error unregistering interface");
    }
  }
  else
  {
    MainMessage("error stopping server");
  }
  MainMessage(SysErrorMessage(status).c_str());

}


// new functions, acting on entire list at once for "atomicity"

void WASetStringList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in][size_is] */ byte __RPC_FAR Buffer[  ],
    /* [in] */ unsigned long BufferLength,
    long command)
{

  EnterCriticalSection(&fCriticalSection);
  try
  {
     try
     {            // test for C++ exceptions
        try
        {         // test for C-based structured exceptions
          MainIdent((char *) pszString);

          TStringList * StringList = new TStringList;
          try
          {
            StringList->Text = (char *) Buffer;

            for (int i = 0 ; i < StringList->Count ; i++)
            {
              ExecuteStringMessage(StringList->Strings[i].c_str(), command);
            }


          }
          __finally
          {
            delete StringList;
          }

          MainStatus(waListening);
        }

        __except(1)
        {
          throw(Exception(AnsiString("structured exception generated in WASetList() : " + SysErrorMessage(RpcExceptionCode()))));
        }
     }
     catch ( Exception &E )
     {
       OutputDebugString(E.Message.c_str());
        if (frmMain->requestlog[EXCEPTIONS])
        {
          MainMessage(strdup(E.Message.c_str()));
        }
      }
    }
   __finally
  {
   LeaveCriticalSection(&fCriticalSection);
  }

}


void WAGetStringList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    long command)
{

  int ListLength;
  EnterCriticalSection(&fCriticalSection);
  try
  {
     try
     {            // test for C++ exceptions
        try
        {         // test for C-based structured exceptions
          MainIdent((char *) pszString);

          TStringList * StringList = new TStringList;
          try
          {
            try
            {
              // get all items in list

              ListLength = GetAmpInt(IPC_GETLISTLENGTH, 0);
              for (int i = 0 ; i < ListLength ; i++)
              {
                StringList->Add(GetAmpStr(command, i));
              }

              char * Buffer = StringList->GetText();
              if (Buffer)
              {
                pBuffer->BufferLength = StringList->Text.Length() + 1;
                pBuffer->Buffer = (unsigned char *) Buffer;
              }
            }
            __finally
            {
              delete StringList;
            }
          }
          catch(...)
          {
            throw(Exception(AnsiString("exception generated in WAGetStringList() : " + SysErrorMessage(GetLastError()))));
          }

          MainStatus(waListening);
        }

        __except(1)
        {
          throw(Exception(AnsiString("structured exception generated in WAGetStringList() : " + SysErrorMessage(RpcExceptionCode()))));
        }
     }
     catch ( Exception &E )
     {
       OutputDebugString(E.Message.c_str());
        if (frmMain->requestlog[EXCEPTIONS])
        {
          MainMessage(strdup(E.Message.c_str()));
        }
      }
    }
   __finally
  {
   LeaveCriticalSection(&fCriticalSection);
  }

}



void WAGetStringDataList(
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    long stringcommand, long intcommand, long intdata)
{

  int ListLength;
  EnterCriticalSection(&fCriticalSection);
  try
  {
     try
     {            // test for C++ exceptions
        try
        {         // test for C-based structured exceptions
          MainIdent((char *) pszString);

          TStringList * StringList = new TStringList;
          try
          {
            try
            {
              // get all items in list

              int i, Index;
              Index = GetAmpInt(IPC_GETLISTPOS, 0);
              ListLength = GetAmpInt(IPC_GETLISTLENGTH, 0);
              for (i = 0 ; i < ListLength ; i++)
              {
                GetAmpInt(IPC_SETPLAYLISTPOS, i);
                // get the string property
                StringList->Add(GetAmpStr(stringcommand, i));
                // add in the integer property for this index

                // set the index
                GetAmpInt(IPC_SETPLAYLISTPOS, i);

                StringList->Add(GetAmpInt(intcommand, intdata));
              }

              // reset the currently playing song
              GetAmpInt(IPC_SETPLAYLISTPOS, Index);


              char * Buffer = StringList->GetText();
              if (Buffer)
              {
                pBuffer->BufferLength = StringList->Text.Length() + 1;
                pBuffer->Buffer = (unsigned char *) Buffer;
              }
            }
            __finally
            {
              delete StringList;
            }
          }
          catch(...)
          {
            throw(Exception(AnsiString("exception generated in WAGetStringDataList() : " + SysErrorMessage(GetLastError()))));
          }

          MainStatus(waListening);
        }

        __except(1)
        {
          throw(Exception(AnsiString("structured exception generated in WAGetStringDataList() : " + SysErrorMessage(RpcExceptionCode()))));
        }
     }
     catch ( Exception &E )
     {
       OutputDebugString(E.Message.c_str());
        if (frmMain->requestlog[EXCEPTIONS])
        {
          MainMessage(strdup(E.Message.c_str()));
        }
      }
    }
   __finally
  {
   LeaveCriticalSection(&fCriticalSection);
  }

}




//---------------------------------------------------------------------------
__fastcall TRPCServerThread::TRPCServerThread(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}

//---------------------------------------------------------------------------

void __fastcall TRPCServerThread::Execute()
{
AnsiString str;
RPC_STATUS status;
int retval;

    unsigned char * protocol_seq_np = "ncacn_np";
//    unsigned char * protocol_seq_ip_tcp = "ncacn_ip_tcp";

    InitializeCriticalSection(&fCriticalSection);
    MainStatus(waServerStarting);

    str = (AnsiString("winamp version : ") + GetWinampVersion());
    MainMessage(str.c_str());

    //test for the buggy versions
    retval = GetAmpInt(IPC_GETVERSION,  0);
    switch (retval)
    {
    // specific cases...
      case 0:
        MainMessage("winamp services not available");
        break;
        /* here we would have version- related messages*/
      default:
        if (retval < 0x2000){
          MainMessage("*** winamp version is rather early : some facilities may not be able ***");
          }
        break;
      }


    // should check status codes here for previously registered interfaces
    status = RpcServerUseProtseqEp(protocol_seq_np,
                                   20,
                                   (unsigned char *) "\\pipe\\winampremote", NULL);
    if (status == RPC_S_OK)
    {
      status = RpcServerRegisterIf(winamp_v1_0_s_ifspec, NULL, NULL);
      if (status == RPC_S_OK)
      {
        MainMessage(strdup( ( AnsiString("RPC server thread initialised OK on endpoint ") + Endpoint).c_str() ) );
        MainStatus(waServerStarted);
        MainStatus(waListening);
        status = RpcServerListen(1, 20, FALSE);
        MainMessage(strdup( ( AnsiString("RPC server thread finished listening on endpoint ") + Endpoint).c_str() ) );
        MainMessage(SysErrorMessage(status).c_str());
        }
    else{
      MainMessage("failed to register interface");
      MainMessage(SysErrorMessage(status).c_str());
      MainStatus(waInitialiseFailed);
      }
    }
  else{
    MainMessage("failed to create protocol sequence");
    MainMessage(SysErrorMessage(status).c_str());
    MainStatus(waInitialiseFailed);
  }

  DeleteCriticalSection(&fCriticalSection);

}

void __fastcall MainMessage(char * msgString)
{
  PostMessage(mainhwnd, WM_THREAD_MESSAGE, 0, (long) strdup(msgString));
}

//---------------------------------------------------------------------------

void __fastcall MainStatus(WAExecutionStatus Status)
{
  PostMessage(mainhwnd, WM_THREAD_STATUS, 0, Status);
}

//---------------------------------------------------------------------------

void __fastcall MainIdent(char * msgString)
{
  PostMessage(mainhwnd, WM_THREAD_IDENT, 0, (long) strdup(msgString));
}

//---------------------------------------------------------------------------

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

//---------------------------------------------------------------------------

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}

//---------------------------------------------------------------------------
