// concrete implementation of ICallObserver

#ifndef CONSOLECALLOBSERVER_H
#define CONSOLECALLOBSERVER_H

#include "ICallObserver.h"

class ConsoleCallObserver : public ICallObserver  {

    public:

    virtual ~ConsoleCallObserver() {};

    virtual void notifyStatus(const char * status);

    virtual void notifyMessage(const char * msg);

};

#endif // CONSOLECALLOBSERVER_H

 