#ifndef RPCExceptionH
#define RPCExceptionH

#include <string>
#include <exception>

using namespace std;

/**
 * class to wrap up RPC error code conversion
 */
class ERPCException : public runtime_error
{

public:
        /**
         * constructor accepting the RPC runtime error code
         * @param rpc_error_code
         */
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

        /**
         * overload of what() to return the value obtained for the RPC code
         * @return
         */
        virtual const char* what() const throw ()
        { return what_.c_str(); }


private:
        std::string what_;
};

#endif
