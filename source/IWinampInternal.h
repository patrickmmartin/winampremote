#ifndef IWINAMPINTERNAL_H
#define IWINAMPINTERNAL_H

// abstract interface wrapping the internal operations Winamp supplies
// via the Windows messages oriented interface

class IWinampInternal {

  public:

    virtual ~IWinampInternal() {}

    void ExecuteMessage(int Command);
    void ExecuteStringMessage(char * CommandString, int Command);
    int GetAmpInt(int Command, int Data);
    char * GetAmpStr(int Command, int Data);
    char * GetWinampVersion(void);
    char * WinampVersion(int retval);

};

#endif // IWINAMPINTERNAL_H
