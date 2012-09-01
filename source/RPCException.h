#ifndef RPCExceptionH
#define RPCExceptionH

#include <string>
#include <exception>
#include <sysutils.hpp>

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

#endif
