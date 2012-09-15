/*
 * RPCBind.h
 *
 *  Created on: 1 Sep 2012
 *      Author: Patrick
 */

#ifndef RPCBIND_H_
#define RPCBIND_H_


// TODO: do we have a definition of these in the SDK headers somewhere?
#define pszProtocolSequenceTCP "ncacn_ip_tcp"
#define pszProtocolSequenceNP "ncacn_np"

extern "C"
{

/**
 *
 * This binds to the interface before the RPC calls can connect
 *
 * @param NetworkAddress - machine name or tcpip address
 * @param EndPoint - destination port/pipe etc. on the machine
 * @param protocolSequence - protocol type
 */
void __stdcall Bind(const char * NetworkAddress, const char * EndPoint, const char * protocolSequence);

/**
 * unbinds from RPC
 */
void __stdcall UnBind(void);

}

#endif /* RPCBIND_H_ */
