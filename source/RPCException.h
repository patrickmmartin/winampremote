#ifndef RPCExceptionH
#define RPCExceptionH

#include <string>
#include <exception>

using namespace std;

class ERPCException : public runtime_error
{

public:
        explicit ERPCException(int rpc_error_code)  :
        std::runtime_error("rpc runtime error"), what_("error message could not be formatted")
        {


			char buffer[255] = "";
			int len = FormatMessageA( FORMAT_MESSAGE_FROM_SYSTEM,
                                                  NULL,
                                                  rpc_error_code,
                                                  LOCALE_USER_DEFAULT,
                                                  buffer,
                                                  sizeof(buffer),
                                                  NULL);

            if (len)
                what_ = buffer;
        }

        virtual const char* what() const throw ()
        { return what_.c_str(); }

        virtual ~ERPCException() throw () {}
private:
        std::string what_;
};

#endif
