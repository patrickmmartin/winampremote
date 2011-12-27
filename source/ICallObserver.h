// abstract interface defining the operations of a Message Observer

#ifndef ICALLOBSERVER_H
#define ICALLOBSERVER_H

class ICallObserver {

  public:

    virtual ~ICallObserver() {}

    virtual void notifyStatus(const char * status) = 0;

    virtual void notifyMessage(const char * msg ) = 0;

};

#endif ICALLOBSERVER_H
