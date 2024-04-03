#ifndef LOGGING
#define LOGGING

#include <stdio.h>

#ifdef DEBUG

extern FILE *diff_log;

#define _OPEN_LOG(arg)\
    diff_log = fopen(arg, "wb");                             \
    if (!diff_log)                                                          \
    {                                                                       \
        fprintf(stderr, ">>> Couldn't open logfile.");                      \
        return ERR;                                                         \
    }                                                                       \
    setbuf(diff_log, NULL)

#define _CLOSE_LOG()\
    fclose(diff_log)

#define LOG(...)  fprintf(diff_log, __VA_ARGS__)

#else
#define _OPEN_LOG(arg)
#define _CLOSE_LOG()
#define LOG(...)
#endif

#endif