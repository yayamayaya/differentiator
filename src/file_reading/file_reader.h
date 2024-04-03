#ifndef FILE_READER
#define FILE_READER

#include <stdio.h>

int read_file(char **buffer_ptr, int *size_of_file, const char *expression_file_loc);
int get_file_size(FILE *expr_file);

#endif