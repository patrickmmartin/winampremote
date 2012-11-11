/*
 * RPCAlloc.cpp
 *
 *  Created on: 11 Nov 2012
 *      Author: Patrick
 */

#include "stdlib.h"
#include "rpc.h"

/* required user alloc / free function pair */
#pragma warning(suppress: 28251)
void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

#pragma warning(suppress: 28251)
void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
    free(ptr);
}




