#include "../headers/main.h"

int read_file(char **buffer_ptr, int *size_of_file, const char *expression_file_loc)
{
    assert(buffer_ptr);
    assert(expression_file_loc);

    FILE *expression_file = fopen(expression_file_loc, "rb");
    if (!expression_file)
    {
        LOG(">>> can't open expression file%40s\n", "[error]");
        return EXPR_FILE_OPEN_ERR;
    }

    int file_size = get_file_size(expression_file);
    LOG("> size of file is: %d\n", file_size);
    if (file_size == 0)
    {
        LOG(">>> couldn't read file: it's empty\n");
        fclose(expression_file);
        return EMPTY_FILE;
    }
    
    
    char *buffer = (char *)calloc(file_size + 1, sizeof(char));
    if (!buffer)
    {
        LOG(">>> can't allocate memory for expression buffer%40s\n", "[error]");
        return BUFF_MEM_ALC_ERR;
    }

    rewind(expression_file);
    if ((int)fread(buffer, sizeof(char), file_size, expression_file) < file_size)
        LOG(">>> file wasn't read fully%40s\n", "[error]");
    

    *buffer_ptr = buffer;
    *size_of_file = file_size;
    LOG(">> file was read\n");
    fclose(expression_file);

    return 0;
}

int get_file_size(FILE *expr_file)
{
    assert(expr_file);

    fseek(expr_file, 0, SEEK_END);
    return ftell(expr_file);
}