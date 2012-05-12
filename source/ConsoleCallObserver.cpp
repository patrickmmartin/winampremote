// implementation of ICallObserver

#include "ConsoleCallObserver.h"
#include <iostream.h>


namespace WinampRemote
{
namespace Remoting
{

void ConsoleCallObserver::notifyStatus(const char * status){

  // output to console
  std::cout << "status: " << ((status)?status:"(null)") << std::endl;

}

void ConsoleCallObserver::notifyMessage(const char * msg ){

  // output to console
  std::cout << "msg  : " << ((msg)?msg:"(null)") << std::endl;

}


} // end of namespace Remoting
} // end of namespace WinampRemote
