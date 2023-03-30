#define KFC
#define BBQ

#ifdef KFC
#define MAC
#else
#undef BBQ
#undef MAC
#endif

#ifndef MAC //not defined 이라면 
#define MOMS
#endif

#ifdef MOMS
HAHA;
#endif