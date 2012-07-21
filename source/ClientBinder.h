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

class ClientBinder
{
public:
	ClientBinder(const char * address, const char * port);
	virtual ~ClientBinder();
};

} /* namespace Client */
} /* namespace WinampRemote */
#endif /* CLIENTBINDER_H_ */
