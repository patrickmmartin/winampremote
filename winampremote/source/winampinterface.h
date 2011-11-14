/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat May 17 20:55:06 2008
 */
/* Compiler settings for winampinterface.idl:
    Os (OptLev=s), W1, Zp8, env=Win32
    error checks: stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __winampinterface_h__
#define __winampinterface_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __winamp_INTERFACE_DEFINED__
#define __winamp_INTERFACE_DEFINED__

/* interface winamp */
/* [implicit_handle][version][uuid] */ 

#define	RET_STR_SIZE	( 260 )

void WAMessageProc( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString);

void WAExecuteMessage( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command);

void WAExecuteMessageString( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [string][in] */ unsigned char __RPC_FAR *pszParam,
    /* [in] */ long command);

long WAIntegerResult( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command,
    /* [in] */ long data);

long WAStringResult( 
    /* [string][out][in] */ unsigned char __RPC_FAR *pszString,
    /* [in] */ long command,
    /* [in] */ long data);

void WAShutdown( void);

void WASetStringList( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [in][size_is] */ byte __RPC_FAR Buffer[  ],
    /* [in] */ unsigned long BufferLength,
    /* [in] */ long command);

typedef /* [public][public][public] */ struct  __MIDL_winamp_0001
    {
    unsigned long BufferLength;
    /* [size_is][unique] */ byte __RPC_FAR *Buffer;
    }	BUFFER;

void WAGetStringList( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    /* [in] */ long command);

void WAGetStringDataList( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [out] */ BUFFER __RPC_FAR *pBuffer,
    /* [in] */ long stringcommand,
    /* [in] */ long datacommand,
    /* [in] */ long datadata);


extern handle_t winamp_IfHandle;


extern RPC_IF_HANDLE winamp_v1_0_c_ifspec;
extern RPC_IF_HANDLE winamp_v1_0_s_ifspec;
#endif /* __winamp_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
