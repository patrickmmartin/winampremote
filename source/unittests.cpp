
#include <vcl.h>

#include <iostream.h>

#pragma hdrstop

#include "NetworkSuite.h"

using std::cout;
using std::endl;


#pragma argsused
int main(int argc, char* argv[])
{
    cout << "unit tests starting" << endl;

    NetworkSuite ns;
    ns.run();

    cout << "unit tests completing" << endl;
    return 0;
}

