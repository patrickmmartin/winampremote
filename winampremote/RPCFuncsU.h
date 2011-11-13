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

/* this binds to the interface before the RPC call*/
extern "C"
{
void __stdcall Bind(unsigned char * NetworkAddress, unsigned char * EndPoint);
void __stdcall UnBind(void);

void __stdcall SendString(char * pszString);
void __stdcall ExecuteMessage(char * pszString, int command);
void __stdcall ExecuteStringMessage(char * pszString, char * pszParam, int command);
int __stdcall StringResult(char * pszString, int command, int data);
int __stdcall IntegerResult(char * pszString, int command, int data);
void __stdcall Shutdown(void);
}


void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len);
void __RPC_USER midl_user_free(void __RPC_FAR * ptr);


#endif
