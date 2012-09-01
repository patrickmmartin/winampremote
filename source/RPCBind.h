/*
 * RPCBind.h
 *
 *  Created on: 1 Sep 2012
 *      Author: Patrick
 */

#ifndef RPCBIND_H_
#define RPCBIND_H_


extern "C"
{

/**
 * this binds to the interface before the RPC calls can connect
 *
 * @param NetworkAddress
 * @param EndPoint
 */
void __stdcall Bind(const char * NetworkAddress, const char * EndPoint);

/**
 * unbinds from RPC
 */
void __stdcall UnBind(void);

}

#endif /* RPCBIND_H_ */
