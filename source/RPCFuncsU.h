//---------------------------------------------------------------------------
#ifndef RPCFuncsUH
#define RPCFuncsUH
//---------------------------------------------------------------------------

#include <rpc.h>

#include "sysutils.hpp"


// supply a simple Exception class


#include <string>
#include <exception>

using namespace std;

class ERPCException : public runtime_error
{

public:
        explicit ERPCException(int rpc_error_code)  :
        std::runtime_error("rpc runtime error"), what_("")
        {
                what_ = SysErrorMessage(rpc_error_code).c_str();
        }

        virtual const char* what() const throw ()
        { return what_.c_str(); }

        virtual ~ERPCException() throw () {}
private:
        std::string what_;
};

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
