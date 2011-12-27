// concrete implementation of ICallObserver

#ifndef DEFAULTCALLOBSERVER_H
#define DEFAULTCALLOBSERVER_H

#include "windows.h"
#include <sstream>

class DefaultCallObserver : public ICallObserver  {

    public:

    virtual ~DefaultCallObserver() {};

    virtual void notifyStatus(const char * status){
        std::stringstream ss;
        ss << "status # " << status;
        OutputDebugString(ss.str().c_str());
    }

    virtual void notifyMessage(const char * msg){
        std::stringstream ss;
        ss << "message # " << msg;
        OutputDebugString(ss.str().c_str());
    }

};

#endif // DEFAULTCALLOBSERVER_H


