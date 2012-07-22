/*
winamp remote control suite ©Patrick Michael Martin 2000 - 2011

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

#include "sysutils.hpp"

#pragma hdrstop

// contains wrappers for the MIDL generated stubs
// define to fix problem of definition of __try in generated c stubs
// no longer required in BCB5 ?
//#define __try try

#include "RPCFuncsU.h"
#include <comutil.h>			// TODO: what do we need this for, remind me?

//TODO: introduce parameter for this selection
// hard-coded for tcpip
//unsigned char * pszProtocolSequence = (unsigned char *) "ncacn_ip_tcp";
unsigned char * pszProtocolSequence = (unsigned char *) "ncacn_np";
// global string binding information
unsigned char * StringBinding = NULL;

extern "C"
{

  void __stdcall ClientFree(void * mem)
  {
    midl_user_free(mem);
  }

  // this binds to the interface , and assigns to the interface handle
  void __stdcall Bind(const char * NetworkAddress, const char * EndPoint)
  {
    // avoid leaking handles ?
    if (StringBinding)
      UnBind();

    RpcStringBindingCompose(NULL,
                            pszProtocolSequence,
                            (unsigned char *) NetworkAddress,
                            (unsigned char *)EndPoint,
                            NULL,
                            &StringBinding);
    RpcBindingFromStringBinding(StringBinding, &winamp_IfHandle);

  }

  // this unbinds to the interface after the RPC call
  void __stdcall UnBind()
  {
      RpcStringFree(&StringBinding);
      StringBinding = NULL;
      RpcBindingFree(&winamp_IfHandle);
  }


  // send a string
  void __stdcall SendString(char * pszString)
  {
    RpcTryExcept
    {
        WAMessageProc( (unsigned char *) pszString);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept;

  }

  // execute a message
  void __stdcall ExecuteMessage(char * pszString, int command)
  {

    RpcTryExcept
    {
       WAExecuteMessage((unsigned char *) pszString, command);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept

  }

  // execute a string message
  void __stdcall ExecuteStringMessage(char * pszString, char * pszParam, int command)
  {

    RpcTryExcept
    {
        WAExecuteMessageString((unsigned char *) pszString, (unsigned char *) pszParam, command);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
  }

  // get the result of a string command
  int __stdcall StringResult(char pszString[WA_RETURN_STRING_SIZE], int command, int data)
  {

  int result = 0;

    RpcTryExcept
    {
        result = WAStringResult(pszString, command, data);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
    return result;
  }

  // get result of a command
  int __stdcall IntegerResult(char * pszString, int command, int data)
  {

    int result = 0;

    RpcTryExcept
    {
       result = WAIntegerResult((unsigned char *) pszString, command, data);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
    return result;
  }

  // shutdown server
  void __stdcall Shutdown(void)
  {

    RpcTryExcept
    {
        WAShutdown();
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
  }


  void __stdcall SetStringList(char * pszString, void * Buffer, int Size, int Command)

  {
    RpcTryExcept
    {
        WASetStringList( (unsigned char *) pszString, (unsigned char *) Buffer, Size, Command);
    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
  }


  void __stdcall GetStringList(char * pszString, void ** Buffer, int& Size, int Command)
  {

    RpcTryExcept
    {

      BUFFER InBuffer;
      InBuffer.BufferLength = 0;
      InBuffer.Buffer = NULL;

      WAGetStringList( ( unsigned char *) pszString, &InBuffer, Command);

      *Buffer = (void *) InBuffer.Buffer;
      Size = InBuffer.BufferLength;

    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
  }


  void _stdcall GetStringDataList(char * pszString, void ** Buffer, int& Size,
                                  int stringcommand, int datacommand, int datadata)
  {
    RpcTryExcept
    {

      BUFFER InBuffer;
      InBuffer.BufferLength = 0;
      InBuffer.Buffer = NULL;

      WAGetStringDataList( ( unsigned char *) pszString, &InBuffer, stringcommand,
                          datacommand, datadata);

      *Buffer = (void *) InBuffer.Buffer;
      Size = InBuffer.BufferLength;

    }
    RpcExcept(1)
    {
        throw ERPCException(RpcExceptionCode());
    }
    RpcEndExcept
  }


  // stub memory allocation functions
  void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
  {
      return(malloc(len));
  }

  void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
  {
      free(ptr);
  }



  int __stdcall SafeSendString(char * pszString)
  {
    RpcTryExcept
    {
      WAMessageProc( (unsigned char *) pszString);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;
  }

  int __stdcall SafeExecuteMessage(char * pszString, int command)
  {
    RpcTryExcept
    {
      WAExecuteMessage( (unsigned char *) pszString, command);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;
  }

  int __stdcall SafeExecuteStringMessage(char * pszString, char * pszParam, int command)
  {
    RpcTryExcept
    {
      WAExecuteMessageString((unsigned char *) pszString, (unsigned char *) pszParam, command);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;
  }

  int __stdcall SafeStringResult(char * pszString, int command, int data, int * Result)
  {
    RpcTryExcept
    {
      *Result = WAStringResult((unsigned char *) pszString, command, data);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;
  }

  int __stdcall SafeIntegerResult(char * pszString, int command, int data, int * Result)
  {
    RpcTryExcept
    {
      *Result = WAIntegerResult((unsigned char *) pszString, command, data);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;
  }

  int __stdcall SafeSetStringList(char * pszString, void * Buffer, int Size, int Command)
  {

    RpcTryExcept
    {
        WASetStringList( (unsigned char *) pszString, (unsigned char *) Buffer, Size, Command);
    }
    RpcExcept(1)
    {
        return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;

  }


  int __stdcall SafeGetStringList(char * pszString, void ** Buffer, int& Size, int Command)
  {
    RpcTryExcept
    {

      BUFFER InBuffer;
      InBuffer.BufferLength = 0;
      InBuffer.Buffer = NULL;

      WAGetStringList( ( unsigned char *) pszString, &InBuffer, Command);

      *Buffer = (void *) InBuffer.Buffer;
      Size = InBuffer.BufferLength;

    }
    RpcExcept(1)
    {
         return RpcExceptionCode();
    }
    RpcEndExcept
    return ERROR_SUCCESS;

  }

/*

  int __stdcall SafeGetStringList(char * pszString, BSTR * Str, int Command)
  {
    RpcTryExcept
    {

      BUFFER InBuffer;
      bstr_t retval;
      InBuffer.BufferLength = 0;
      InBuffer.Buffer = NULL;

      WAGetStringList( ( unsigned char *) pszString, &InBuffer, Command);

      retval = (char *) InBuffer.Buffer;
      *Str = retval;
      return ERROR_SUCCESS;

    }
    RpcExcept(1)
    {
         return RpcExceptionCode();
    }
    RpcEndExcept

  }

*/
}// extern "c"

