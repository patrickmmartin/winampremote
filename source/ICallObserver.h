// abstract interface defining the operations of a Message Observer

#ifndef ICALLOBSERVER_H
#define ICALLOBSERVER_H


namespace WinampRemote
{

/**
 * interface defining observable operations
 */
namespace Remoting
{

/**
 * interface for call event observation
 */
class ICallObserver {

  public:

    /**
     * virtual destructor
     */
	virtual ~ICallObserver() {}

	/**
     * outputs status
     * @param status
     */
	virtual void notifyStatus(const char * status) = 0;

    /**
     * outputs a message
     * @param msg
     */
	virtual void notifyMessage(const char * msg ) = 0;

    /**
     * notification for an error
     * @param msg
     */
	virtual void notifyException(const char * msg ) = 0;

};

} // end of namespace Remoting
} // end of namespace WinampRemote

#endif ICALLOBSERVER_H
