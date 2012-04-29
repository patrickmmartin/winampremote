// concrete implementation of ICallObserver

#ifndef CONSOLECALLOBSERVER_H
#define CONSOLECALLOBSERVER_H

#include "ICallObserver.h"

namespace WinampRemote
{
namespace Remoting
{

class ConsoleCallObserver : public ICallObserver  {

    public:

    virtual ~ConsoleCallObserver() {};

    virtual void notifyStatus(const char * status);

    virtual void notifyMessage(const char * msg);

};

} // end of namespace Remoting
} // end of namespace WinampRemote

#endif // CONSOLECALLOBSERVER_H

