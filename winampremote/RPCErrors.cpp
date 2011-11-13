//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RPCErrors.h"


char * RPCError(int RPCErr){

switch (RPCErr){
  case EPT_S_CANT_CREATE: return "The endpoint-map database cannot be created.";
  case EPT_S_CANT_PERFORM_OP: return "The operation cannot be performed.";
  case EPT_S_INVALID_ENTRY: return "The entry is invalid.";
  case EPT_S_NOT_REGISTERED: return "There are no more endpoints available from the endpoint-map database.";
  case RPC_S_ACCESS_DENIED: return "The user does not have sufficient privilege to complete the operation.";
  case RPC_S_ADDRESS_ERROR: return "An addressing error has occurred on the server.";
  case RPC_S_ALREADY_LISTENING: return "The server is already listening.";
  case RPC_S_ALREADY_REGISTERED: return "The object UUID has already been registered.";
  case RPC_S_BINDING_HAS_NO_AUTH: return "The binding does not contain any authentication information.";
  case RPC_S_BINDING_INCOMPLETE: return "The binding handle is a required parameter.";
  case RPC_S_BUFFER_TOO_SMALL: return "The buffer used to transmit data is too small.";
  case RPC_S_CALL_CANCELLED: return "The remote procedure call exceeded the cancel timeout and was cancelled.";
  case RPC_S_CALL_FAILED: return "The remote procedure call failed.";
  case RPC_S_CALL_FAILED_DNE: return "The remote procedure call failed and did not execute.";
  case RPC_S_CALL_IN_PROGRESS: return "A remote procedure call is already in progress for this thread.";
  case RPC_S_CANNOT_SUPPORT: return "The requested operation is not supported.";
  case RPC_S_CANT_CREATE_ENDPOINT: return "The endpoint cannot be created.";
  case RPC_S_COMM_FAILURE: return "Unable to communicate with the server.";
  case RPC_S_DUPLICATE_ENDPOINT: return "The endpoint is a duplicate.";
  case RPC_S_ENTRY_ALREADY_EXISTS: return "The entry already exists.";
  case RPC_S_ENTRY_NOT_FOUND: return "The entry is not found.";
  case RPC_S_FP_DIV_ZERO: return "A floating-point operation at the server has caused a divide by zero.";
  case RPC_S_FP_OVERFLOW: return "A floating-point overflow has occurred at the server.";
  case RPC_S_FP_UNDERFLOW: return "A floating-point underflow occurred at the server.";
  case RPC_S_GROUP_MEMBER_NOT_FOUND: return "The group member has not been found.";
  case RPC_S_INCOMPLETE_NAME: return "The entry name is incomplete.";
  case RPC_S_INTERFACE_NOT_FOUND: return "The interface has not been found.";
  case RPC_S_INTERNAL_ERROR: return "An internal error has occurred in a remote procedure call.";
  case RPC_S_INVALID_ARG: return "The specified argument is not valid.";
  case RPC_S_INVALID_AUTH_IDENTITY: return "The security context is invalid.";
  case RPC_S_INVALID_BINDING: return "The binding handle is invalid.";
  case RPC_S_INVALID_BOUND: return "The array bounds are invalid.";
  case RPC_S_INVALID_ENDPOINT_FORMAT: return "The endpoint format is invalid.";
//  case RPC_S_INVALID_LEVEL: return "The level parameter is invalid.";
  case RPC_S_INVALID_NAF_ID: return "The network-address family is invalid.";
  case RPC_S_INVALID_NAME_SYNTAX: return "The name syntax is invalid.";
  case RPC_S_INVALID_NET_ADDR: return "The network address is invalid.";
  case RPC_S_INVALID_NETWORK_OPTIONS: return "The network options are invalid.";
  case RPC_S_INVALID_OBJECT: return "The object is invalid.";
  case RPC_S_INVALID_RPC_PROTSEQ: return "The RPC protocol sequence is invalid.";
  case RPC_S_INVALID_SECURITY_DESC: return "The security descriptor is not in the valid format.";
  case RPC_S_INVALID_STRING_BINDING: return "The string binding is invalid.";
  case RPC_S_INVALID_STRING_UUID: return "The string UUID is invalid.";
  case RPC_S_INVALID_TAG: return "The discriminant value does not match any of the case values.\nThere is no default case.";
  case RPC_S_INVALID_TIMEOUT: return "The timeout value is invalid.";
  case RPC_S_INVALID_VERS_OPTION: return "The version option is invalid.";
  case RPC_S_MAX_CALLS_TOO_SMALL: return "The maximum number of calls is too small.";
  case RPC_S_NAME_SERVICE_UNAVAILABLE: return "The name service is unavailable.";
  case RPC_S_NO_BINDINGS: return "There are no bindings.";
  case RPC_S_NO_CALL_ACTIVE: return "There is no remote procedure call active in this thread.";
  case RPC_S_NO_CONTEXT_AVAILABLE: return "No security context is available to allow impersonation.";
  case RPC_S_NO_ENDPOINT_FOUND: return "No endpoint has been found.";
  case RPC_S_NO_ENTRY_NAME: return "The binding does not contain an entry name.";
//  case RPC_S_NO_ENV_SETUP: return "No environment variable is set up.";
  case RPC_S_NO_INTERFACES: return "No interfaces are registered.";
//  case RPC_S_NO_INTERFACES_EXPORTED: return "No interfaces have been exported.";
  case RPC_S_NO_MORE_BINDINGS: return "There are no more bindings.";
//  case RPC_S_NO_MORE_ELEMENTS: return "There are no more elements.";
  case RPC_S_NO_MORE_MEMBERS: return "There are no more members.";
//  case RPC_S_NO_NS_PRIVILEGE: return "There is no privilege for a name-service operation.";
  case RPC_S_NO_PRINC_NAME: return "No principal name is registered.";
  case RPC_S_NO_PROTSEQS: return "There are no protocol sequences.";
  case RPC_S_NO_PROTSEQS_REGISTERED: return "No protocol sequences have been registered.";
  case RPC_S_NOT_ALL_OBJS_UNEXPORTED: return "Not all objects are unexported.";
  case RPC_S_NOT_CANCELLED: return "The thread is not cancelled.";
  case RPC_S_NOT_LISTENING: return "The server is not listening.";
  case RPC_S_NOT_RPC_ERROR: return "The status code requested is not valid.";
  case RPC_S_NOTHING_TO_EXPORT: return "There is nothing to export.";
  case RPC_S_OBJECT_NOT_FOUND: return "The object UUID has not been found.";
  case RPC_S_OK: return "The call has completed successfully.";
  case RPC_S_OUT_OF_MEMORY: return "The needed memory is not available.";
  case RPC_S_OUT_OF_RESOURCES: return "Not enough resources are available to complete this operation.";
  case RPC_S_OUT_OF_THREADS: return "The RPC run-time library was not able to create another thread.";
  case RPC_S_PROCNUM_OUT_OF_RANGE: return "The procedure number is out of range.";
  case RPC_S_PROTOCOL_ERROR: return "An RPC protocol error has occurred.";
  case RPC_S_PROTSEQ_NOT_FOUND: return "The RPC protocol sequence has not been found.";
  case RPC_S_PROTSEQ_NOT_SUPPORTED: return "The RPC protocol sequence is not supported.";
  case RPC_S_SEC_PKG_ERROR: return "There is an error with the security package.";
//  case RPC_S_SERVER_NOT_LISTENING: return "The server is not listening for remote procedure calls.";
  case RPC_S_SERVER_OUT_OF_MEMORY: return "The server has insufficient memory to complete this operation.";
  case RPC_S_SERVER_TOO_BUSY: return "The server is too busy to complete this operation.";
  case RPC_S_SERVER_UNAVAILABLE: return "The server is unavailable.";
  case RPC_S_STRING_TOO_LONG: return "The string is too long.";
  case RPC_S_TYPE_ALREADY_REGISTERED: return "The type UUID has already been registered.";
  case RPC_S_UNKNOWN_AUTHN_LEVEL: return "The authentication level is unknown.";
  case RPC_S_UNKNOWN_AUTHN_SERVICE: return "The authentication service is unknown.";
  case RPC_S_UNKNOWN_AUTHN_TYPE: return "The authentication type is unknown.";
  case RPC_S_UNKNOWN_AUTHZ_SERVICE: return "The authorization service is unknown.";
  case RPC_S_UNKNOWN_IF: return "The interface is unknown.";
  case RPC_S_UNKNOWN_MGR_TYPE: return "The manager type is unknown.";
  case RPC_S_UNSUPPORTED_AUTHN_LEVEL: return "The authentication level is not supported.";
  case RPC_S_UNSUPPORTED_NAME_SYNTAX: return "The name syntax is not supported.";
  case RPC_S_UNSUPPORTED_TRANS_SYN: return "The transfer syntax is not supported by the server.";
  case RPC_S_UNSUPPORTED_TYPE: return "The type UUID is not supported.";
  case RPC_S_UUID_LOCAL_ONLY: return "The UUID that is only valid for this computer has been allocated.";
  case RPC_S_UUID_NO_ADDRESS: return "No network address is available for constructing a UUID.";
  case RPC_S_WRONG_KIND_OF_BINDING: return "The binding handle is not the correct type.";
  case RPC_S_ZERO_DIVIDE: return "The server has attempted an integer divide by zero.";
  case RPC_X_BAD_STUB_DATA: return "The stub has received bad data.";
//  case RPC_X_BYTE_COUNT_TOO_SMAL: return "The byte count is too small.";
  case RPC_X_ENUM_VALUE_OUT_OF_RANGE: return "The enumeration value is out of range.";
//  case RPC_X_ENUM_VALUE_TOO_LARGE: return "The enumeration constant must be less than 65535.";
//  case RPC_X_INVALID_BOUND: return "The specified bounds of an array are inconsistent.";
//  case RPC_X_INVALID_TAG: return "The discriminant value does not match any of the case values. There is no default case.";
//  case RPC_X_NO_MEMORY: return "Insufficient memory is available.";
  case RPC_X_NO_MORE_ENTRIES: return "The list of servers available for the auto_handle binding has been exhausted.";
  case RPC_X_NULL_REF_POINTER: return "A null reference pointer has been passed to the stub.";
//  case RPC_X_SS_BAD_ES_VERSION: return "The operation for the serializing handle is not valid.";
  case RPC_X_SS_CANNOT_GET_CALL_HANDLE: return "The stub is unable to get the call handle.";
  case RPC_X_SS_CHAR_TRANS_OPEN_FAIL: return "The file designated by DCERPCCHARTRANS cannot be opened.";
  case RPC_X_SS_CHAR_TRANS_SHORT_FILE: return "The file containing the character-translation table has fewer than 512 bytes.";
  case RPC_X_SS_CONTEXT_DAMAGED: return "The context handle changed during a call.\nOnly raised on the client side.";
  case RPC_X_SS_CONTEXT_MISMATCH: return "The context handle does not match any known context handles.";
  case RPC_X_SS_HANDLES_MISMATCH: return "The binding handles passed to a remote procedure call do not match.";
  case RPC_X_SS_IN_NULL_CONTEXT: return "A null context handle is passed in an in parameter position.";
//  case RPC_X_SS_INVALID_BUFFER: return "The buffer is not valid for the operation.";
//  case RPC_X_SS_WRONG_ES_VERSION: return "The software version is incorrect.";
//  case RPC_X_SS_WRONG_STUB_VERSION: return "The stub version is incorrect.";
 default:
   return "unknown RPC error";
   }
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
