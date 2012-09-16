
#ifndef RFC1060UH
#define RFC1060UH

#endif

struct porttype
  {
    char * service  ;
    short port ;
    char * description  ;
  };

extern porttype RFC1060ports[];
extern int RFC1060portscount;
