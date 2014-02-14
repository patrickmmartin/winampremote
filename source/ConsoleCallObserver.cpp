// implementation of ICallObserver

#include "ConsoleCallObserver.h"
#include <iostream>


namespace WinampRemote
{
namespace Remoting
{

void ConsoleCallObserver::notifyStatus(const char * status) const{

  // output to console
  std::cout << "status: " << ((status)?status:"(null)") << std::endl;

}

void ConsoleCallObserver::notifyMessage(const char * msg ) const{

  // output to console
  std::cout << "msg  : " << ((msg)?msg:"(null)") << std::endl;

}

void ConsoleCallObserver::notifyException(const char * msg ) const
{
	  // output to console
	  std::cerr << "error: " << ((msg)?msg:"(null)") << std::endl;
}

} // end of namespace Remoting
} // end of namespace WinampRemote
