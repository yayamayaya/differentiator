#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdarg.h>
#include "debugging.hpp"
#include <sys/stat.h>

#define DIR_PATH "./logging"
#define LOG_PATH "./logging/differentiator.log"

static FILE *log_file = NULL;

void open_log()
{
    DIR *dir = opendir(DIR_PATH); 
    if (!dir)
    {
        LOG("> no logging folder present, creating logging folder...\n");
        int ret_val = mkdir(DIR_PATH, 0777);
        if (ret_val == -1) LOG_ERR("> dir create error:");

        open_log();
        return;
    }
    
    closedir(dir);

    log_file = fopen(LOG_PATH, "wb");
    if (!log_file) printf("> couldn't open log file for server, resuming work without logs\n");
    
    return;
}

void close_log()
{
    if (log_file) fclose(log_file);

    log_file = NULL;
}

void loggg(const char *format, ...)
{
    if (!log_file) return;

    time_t t;
    time(&t);
    fprintf(log_file, "[%s]", strtok(ctime(&t), "\n"));

    va_list args;
    va_start(args, format);

    vfprintf(log_file, format, args);

    va_end(args);
    fflush(log_file);
}

void err_log(const char *format)
{
    if (!log_file) return;

    time_t t;
    time(&t);
    fprintf(log_file, "[%s]", strtok(ctime(&t), "\n"));

    fprintf(log_file, "%s %s\n", format, strerror(errno));
}