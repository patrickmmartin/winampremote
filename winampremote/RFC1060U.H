//---------------------------------------------------------------------------
#ifndef RFC1060UH
#define RFC1060UH
//---------------------------------------------------------------------------
#endif

struct porttype
  {
    char service[21]  ;
    short port ;
    char description[100]  ;
  };

extern porttype RFC1060ports[];
extern int RFC1060portscount;
