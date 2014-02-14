// concrete implementation of ICallObserver

#ifndef DEFAULTCALLOBSERVER_H
#define DEFAULTCALLOBSERVER_H

#include "windows.h"
#include <sstream>

using namespace WinampRemote::Remoting;

class DefaultCallObserver : public ICallObserver  {

    public:

    virtual ~DefaultCallObserver() {};

    virtual void notifyStatus(const char * status) const{
        std::stringstream ss;
        ss << "status # " << status;
        OutputDebugString(ss.str().c_str());
    }

    virtual void notifyMessage(const char * msg) const{
        std::stringstream ss;
        ss << "message # " << msg;
        OutputDebugString(ss.str().c_str());
    }

};

#endif // DEFAULTCALLOBSERVER_H


