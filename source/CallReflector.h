/*
 * CallReflector.h
 *
 *  Created on: 13 May 2012
 *      Author: Patrick
 */

#include <vcl.h>

#include "waint.h"

#include "ICallObserver.h"

#ifndef CALLREFLECTOR_H_
#define CALLREFLECTOR_H_

namespace WinampRemote
{
namespace Remoting
{


/**
 * Closure for the Status event.
 * @param statusMessage
 */
typedef void (__closure *TCOStatusEvent)(const AnsiString& statusMessage);

/**
 * Closure for the Info event.
 * @param infoMessage
 */
typedef void (__closure *TCOInfoEvent)(const AnsiString& infoMessage);

/**
 * Closure for the Ident event.
 * @param statusMessage
 */
typedef void (__closure *TCOIdentEvent)(const AnsiString& identMessage);



class CallReflector: public ICallObserver  {

	public:

	virtual ~CallReflector() {};

	virtual void notifyStatus(const char * status);

	virtual void notifyMessage(const char * msg);

    /**
     * closure property for the ident event
     */
    __property TCOIdentEvent OnIdent = {read = _identEvent, write = _identEvent};

    /**
     * closure property for the info event
     */
    __property TCOInfoEvent OnInfo = {read = _statusEvent, write = _statusEvent};

    /**
     * closure property for the status event
     */
    __property TCOStatusEvent OnStatus = {read = _infoEvent, write = _infoEvent};


	private:

    TCOIdentEvent _identEvent;
    TCOInfoEvent _statusEvent;
    TCOStatusEvent _infoEvent;


};

} /* namespace Remoting */
} /* namespace WinampRemote */
#endif /* CALLREFLECTOR_H_ */
