//---------------------------------------------------------------------------

#ifndef ContextInfoH
#define ContextInfoH
//---------------------------------------------------------------------------


#include <string>

/**
 * namespace for the WinampRemote project
 */
namespace WinampRemote
{

/**
 * namespace for the use of context classes
 */
namespace Context
{

/**
 * A simple context class to return machine name and user name
 */
class ContextInfo
{

public:

	/**
	 * no - params constructor
	 */
	ContextInfo();

	/**
	 * destructor
	 */
	virtual ~ContextInfo()
	{
	}

        std::string const computername() { return m_computername; };
        std::string const username() { return m_username; };


private:

        std::string m_computername;
        std::string m_username;



};
} // end of namespace Context
} // end of namespace WinampRemote

#endif
