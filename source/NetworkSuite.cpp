/*
 * NetworkSuite.cpp
 *
 *  Created on: 11 Feb 2012
 *      Author: Patrick
 */

#include "NetworkSuite.h"

#include "ServerEnumerator.h"

NetworkSuite::NetworkSuite()
{
  // TODO Auto-generated stub
}

NetworkSuite::~NetworkSuite()
{
  // TODO Auto-generated stub
}


void NetworkSuite::run()
{

  ServerEnumerator se;
  se.enumerateServers();

}
