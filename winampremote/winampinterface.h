/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun May 18 22:33:51 2008
 */
/* Compiler settings for winampinterface.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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
    int command);

void WAExecuteMessageString( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    /* [string][in] */ unsigned char __RPC_FAR *pszParam,
    int command);

int WAIntegerResult( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

int WAStringResult( 
    /* [size_is][string][out][in] */ unsigned char __RPC_FAR *pszString,
    int command,
    int data);

void WAShutdown( void);


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
