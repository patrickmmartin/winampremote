/*
 * StringVectorPrinter.h
 *
 *  Created on: 24 Feb 2013
 *      Author: Patrick
 */

#ifndef STRINGVECTORPRINTER_H_
#define STRINGVECTORPRINTER_H_

#include <sstream.h>
#include <vector>

namespace WinampRemote
{
namespace Utils
{

/**
 * class to wrap up the task of pretty printing
 */
struct StringVectorPrinter
{

	stringstream sstr;

	/**
	 * constructor accepting vector<string>
	 * @param playlist - string vector
	 */
	StringVectorPrinter(vector<string> & playlist)
	{
		for (unsigned int i = 0; i < playlist.size(); i++)
		{
			sstr << (playlist.at(i)).c_str() << endl;
		}
	}


};


/**
 * stream operator to pretty print the vector passed when constructed
 * @param os
 * @param svp
 * @return
 */
std::ostream& operator <<(std::ostream& os, const StringVectorPrinter& svp)
{
	os << svp.sstr.str();
	return os;
}

} /* namespace Utils */
} /* namespace WinampRemote */
#endif /* STRINGVECTORPRINTER_H_ */
