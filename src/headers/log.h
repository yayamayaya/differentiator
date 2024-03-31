#ifndef LOGGING
#define LOGGING

#include <stdio.h>

extern FILE *diff_log;
#define LOG(...)  fprintf(diff_log, __VA_ARGS__)

#endif