//---------------------------------------------------------------------------
#ifndef RPCFuncsUH
#define RPCFuncsUH
//---------------------------------------------------------------------------

#include <rpc.h>

#ifndef NO_VCL_EXCEPTION

#include "sysutils.hpp"

//class ERPCException based upon VCL Exception
class ERPCException : public Sysutils::Exception
{
public:
	 __fastcall ERPCException(const System::AnsiString Msg) : Sysutils::Exception(Msg)
            { }
};

#else

// supply a simple Exception class


#include <string>
using namespace std;

class ERPCException
{
public:
         string Message;
	 ERPCException(const string Msg)
           {Message = Msg;}
};


#endif

extern "C"
{
/* this binds to the interface before the RPC call*/
void __stdcall Bind(char * NetworkAddress, char * EndPoint);
void __stdcall UnBind(void);

void __stdcall SendString(char * pszString);
void __stdcall ExecuteMessage(char * pszString, int command);
void __stdcall ExecuteStringMessage(char * pszString, char * pszParam, int command);
int __stdcall StringResult(char * pszString, int command, int data);
int __stdcall IntegerResult(char * pszString, int command, int data);
void __stdcall Shutdown(void);

void __stdcall SetStringList(char * pszString, void * Buffer, int Size, int Command);
void __stdcall GetStringList(char * pszString, void ** Buffer, int& Size, int Command);
void _stdcall GetStringDataList(char * pszString, void ** Buffer, int& Size,
                                int stringcommand, int datacommand, int datadata);


// provide some exception safe versions

int __stdcall SafeSendString(char * pszString);
int __stdcall SafeExecuteMessage(char * pszString, int command);
int __stdcall SafeExecuteStringMessage(char * pszString, char * pszParam, int command);
int __stdcall SafeStringResult(char * pszString, int command, int data, int * Result);
int __stdcall SafeIntegerResult(char * pszString, int command, int data, int * Result);


}

// need to declare these somewhere

void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);


#endif
