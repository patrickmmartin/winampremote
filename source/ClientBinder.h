/*
 * ClientBinder.h
 *
 *  Created on: 15 Jul 2012
 *      Author: Patrick
 */

#ifndef CLIENTBINDER_H_
#define CLIENTBINDER_H_

namespace WinampRemote
{
namespace Client
{

/**
 * class to wrap up the task of binding the RPC global context
 */
class ClientBinder
{
public:
	/**
	 * Binds the global RPC binding handle to the address and port
	 * @param address
	 * @param port
	 */
	ClientBinder(const char * address, const char * port);
	virtual ~ClientBinder();
};

} /* namespace Client */
} /* namespace WinampRemote */
#endif /* CLIENTBINDER_H_ */
