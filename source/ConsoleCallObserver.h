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

    virtual void notifyStatus(const char * status) const;

    virtual void notifyMessage(const char * msg) const;

    virtual void notifyException(const char * msg) const;
};

} // end of namespace Remoting
} // end of namespace WinampRemote

#endif // CONSOLECALLOBSERVER_H

