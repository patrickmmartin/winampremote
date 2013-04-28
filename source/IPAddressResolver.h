/*
 * IPAddressResolver.h
 *
 *  Created on: 9 Feb 2013
 *      Author: Patrick
 */

#ifndef IPADDRESSRESOLVER_H_
#define IPADDRESSRESOLVER_H_

#include <vector.h>
#include <string.h>

namespace WinampRemote
{
namespace Net
{

class IPAddressResolver
{
private:
	std::vector<std::string> m_addresses;
	std::vector<std::string> m_aliases;
	std::string m_hostname;
	std::string m_resolved;
public:
	IPAddressResolver(std::string& const hostname);
	virtual ~IPAddressResolver();

	std::vector<std::string> & getAddresses();
	std::vector<std::string> & getAliases();
	std::string const & hostname() const;
	std::string const & resolvedName() const;

};

} /* namespace Net */
} /* namespace WinampRemote */
#endif /* IPADDRESSRESOLVER_H_ */
