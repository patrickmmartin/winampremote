/* this ALWAYS GENERATED file contains the RPC server stubs */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat May 17 20:55:06 2008
 */
/* Compiler settings for winampinterface.idl:
    Os (OptLev=s), W1, Zp8, env=Win32
    error checks: stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#include "winampinterface.h"

#define TYPE_FORMAT_STRING_SIZE   51                                
#define PROC_FORMAT_STRING_SIZE   91                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;

extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/* Standard interface: winamp, ver. 1.0,
   GUID={0xDBA14E47,0xF2F4,0x11D3,{0x9C,0xCE,0x90,0xA8,0xEF,0x7A,0xA9,0x61}} */


extern RPC_DISPATCH_TABLE winamp_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE winamp___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xDBA14E47,0xF2F4,0x11D3,{0x9C,0xCE,0x90,0xA8,0xEF,0x7A,0xA9,0x61}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &winamp_v1_0_DispatchTable,
    0,
    0,
    0,
    0,
    0
    };
RPC_IF_HANDLE winamp_v1_0_s_ifspec = (RPC_IF_HANDLE)& winamp___RpcServerInterface;

extern const MIDL_STUB_DESC winamp_StubDesc;

void __RPC_STUB
winamp_WAMessageProc(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    ( unsigned char __RPC_FAR * )pszString = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        WAMessageProc(pszString);
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAExecuteMessage(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    long command;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    ( unsigned char __RPC_FAR * )pszString = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        WAExecuteMessage(pszString,command);
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAExecuteMessageString(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    long command;
    unsigned char __RPC_FAR *pszParam;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    ( unsigned char __RPC_FAR * )pszString = 0;
    ( unsigned char __RPC_FAR * )pszParam = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[14] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszParam,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        WAExecuteMessageString(
                          pszString,
                          pszParam,
                          command);
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAIntegerResult(
    PRPC_MESSAGE _pRpcMessage )
{
    long _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long command;
    long data;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    ( unsigned char __RPC_FAR * )pszString = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[26] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            data = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        _RetVal = WAIntegerResult(
                          pszString,
                          command,
                          data);
        
        _StubMsg.BufferLength = 4U;
        _StubMsg.BufferLength += 16;
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAStringResult(
    PRPC_MESSAGE _pRpcMessage )
{
    long _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long command;
    long data;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    ( unsigned char __RPC_FAR * )pszString = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[36] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            data = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        _RetVal = WAStringResult(
                         pszString,
                         command,
                         data);
        
        _StubMsg.BufferLength = 12U + 11U;
        NdrConformantStringBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)pszString,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4] );
        
        _StubMsg.BufferLength += 16;
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        NdrConformantStringMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)pszString,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAShutdown(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    RpcTryFinally
        {
        RpcTryExcept
            {
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        WAShutdown();
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WASetStringList(
    PRPC_MESSAGE _pRpcMessage )
{
    byte ( __RPC_FAR *Buffer )[  ];
    unsigned long BufferLength;
    MIDL_STUB_MESSAGE _StubMsg;
    long command;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    NdrRpcSsEnableAllocate(&_StubMsg);
    ( unsigned char __RPC_FAR * )pszString = 0;
    Buffer = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[48] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            NdrConformantArrayUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                          (unsigned char __RPC_FAR * __RPC_FAR *)&Buffer,
                                          (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[6],
                                          (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            BufferLength = *(( unsigned long __RPC_FAR * )_StubMsg.Buffer)++;
            
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        
        WASetStringList(
                   pszString,
                   *Buffer,
                   BufferLength,
                   command);
        
        }
    RpcFinally
        {
        NdrRpcSsDisableAllocate(&_StubMsg);
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAGetStringList(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    BUFFER _pBufferM;
    long command;
    BUFFER __RPC_FAR *pBuffer;
    unsigned char __RPC_FAR *pszString;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    NdrRpcSsEnableAllocate(&_StubMsg);
    ( unsigned char __RPC_FAR * )pszString = 0;
    ( BUFFER __RPC_FAR * )pBuffer = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[62] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            command = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        pBuffer = &_pBufferM;
        pBuffer -> Buffer = 0;
        
        WAGetStringList(
                   pszString,
                   pBuffer,
                   command);
        
        _StubMsg.BufferLength = 0U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pBuffer,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[30] );
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pBuffer,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[30] );
        
        }
    RpcFinally
        {
        NdrRpcSsDisableAllocate(&_StubMsg);
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
winamp_WAGetStringDataList(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    BUFFER _pBufferM;
    long datacommand;
    long datadata;
    BUFFER __RPC_FAR *pBuffer;
    unsigned char __RPC_FAR *pszString;
    long stringcommand;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &winamp_StubDesc);
    
    NdrRpcSsEnableAllocate(&_StubMsg);
    ( unsigned char __RPC_FAR * )pszString = 0;
    ( BUFFER __RPC_FAR * )pBuffer = 0;
    RpcTryFinally
        {
        RpcTryExcept
            {
            if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[74] );
            
            NdrConformantStringUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR * __RPC_FAR *)&pszString,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4],
                                           (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            stringcommand = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            datacommand = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            datadata = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            if(_StubMsg.Buffer > _StubMsg.BufferEnd)
                {
                RpcRaiseException(RPC_X_BAD_STUB_DATA);
                }
            }
        RpcExcept( RPC_BAD_STUB_DATA_EXCEPTION_FILTER )
            {
            RpcRaiseException(RPC_X_BAD_STUB_DATA);
            }
        RpcEndExcept
        pBuffer = &_pBufferM;
        pBuffer -> Buffer = 0;
        
        WAGetStringDataList(
                       pszString,
                       pBuffer,
                       stringcommand,
                       datacommand,
                       datadata);
        
        _StubMsg.BufferLength = 0U;
        NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR *)pBuffer,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[30] );
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                 (unsigned char __RPC_FAR *)pBuffer,
                                 (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[30] );
        
        }
    RpcFinally
        {
        NdrRpcSsDisableAllocate(&_StubMsg);
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


static const MIDL_STUB_DESC winamp_StubDesc = 
    {
    (void __RPC_FAR *)& winamp___RpcServerInterface,
    NdrRpcSsDefaultAllocate,
    NdrRpcSsDefaultFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static RPC_DISPATCH_FUNCTION winamp_table[] =
    {
    winamp_WAMessageProc,
    winamp_WAExecuteMessage,
    winamp_WAExecuteMessageString,
    winamp_WAIntegerResult,
    winamp_WAStringResult,
    winamp_WAShutdown,
    winamp_WASetStringList,
    winamp_WAGetStringList,
    winamp_WAGetStringDataList,
    0
    };
RPC_DISPATCH_TABLE winamp_v1_0_DispatchTable = 
    {
    9,
    winamp_table
    };

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  2 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/*  4 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  8 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 10 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 12 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 14 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 16 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 18 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 20 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 22 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 24 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 26 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 30 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 32 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 34 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 36 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 38 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 40 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 42 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 44 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 46 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 48 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 50 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 52 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 54 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */
/* 56 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 58 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 60 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 62 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 64 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 66 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 68 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */
/* 70 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 72 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 76 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/* 78 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 80 */	NdrFcShort( 0x10 ),	/* Type Offset=16 */
/* 82 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 84 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 86 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 88 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x1 ),	/* 1 */
/* 10 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
#ifndef _ALPHA_
/* 12 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 14 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 16 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 18 */	NdrFcShort( 0xc ),	/* Offset= 12 (30) */
/* 20 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 22 */	NdrFcShort( 0x1 ),	/* 1 */
/* 24 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 30 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 32 */	NdrFcShort( 0x8 ),	/* 8 */
/* 34 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 36 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 38 */	NdrFcShort( 0x4 ),	/* 4 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	0x12, 0x0,	/* FC_UP */
/* 44 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (20) */
/* 46 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 48 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };
