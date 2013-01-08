#include "windows.h"

#pragma hdrstop

#include "ContextInfo.h"

namespace WinampRemote
{

namespace Context
{


ContextInfo::ContextInfo() : m_computername(), m_username() 
{
	char NameBuf[MAX_COMPUTERNAME_LENGTH + 1];
        char ComputerBuf [MAX_COMPUTERNAME_LENGTH + 1];

	unsigned long BufLen;
	BufLen = MAX_COMPUTERNAME_LENGTH + 1;
	GetComputerName(ComputerBuf, &BufLen);
	BufLen = MAX_COMPUTERNAME_LENGTH + 1;
	GetUserName(NameBuf, &BufLen);
        m_computername =  ComputerBuf;
        m_username =  NameBuf;
}

} // end of namespace Context
} // end of namespace WinampRemote
