#include "main_header.h"

int read_file(char ***token_arr_ptr, const char *expression_file_loc)
{
    assert(token_arr_ptr);
    assert(expression_file_loc);

    FILE *expression_file = fopen(expression_file_loc, "rb");
    if (!expression_file)
    {
        LOG(">>> can't open expression file%40s\n", "[error]");
        return EXPR_FILE_OPEN_ERR;
    }

    int file_size = get_file_size(expression_file);

    LOG("> size of file is: %d\n", file_size);
    char *buffer = (char *)calloc(file_size + 1, sizeof(char));
    if (!buffer)
    {
        LOG(">>> can't allocate memory for expression buffer%40s\n", "[error]");
        return BUFF_MEM_ALC_ERR;
    }

    rewind(expression_file);
    if ((int)fread(buffer, sizeof(char), file_size, expression_file) < file_size)
        LOG(">>> file wasn't read fully%40s\n", "[error]");

    char **token_arr = 0;

    tokenization(&token_arr, buffer, file_size);
    if (!token_arr)
    {
        LOG(">>> token array wasn't created due to error%40s\n", "[error]");
        return TOKEN_ARR_NULL;
    }

    fprintf(stderr, "token array pointer :%p\n", token_arr);
    for (int i = 0; i < 400; i++)
    {
        fprintf(stderr, "<%c>", *token_arr[i]);
    }

    *token_arr_ptr = token_arr;
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

int tokenization(char ***token_arr, char *buff, const int buff_size)
{
    assert(token_arr);
    assert(buff);

    char **temp_token_arr = (char **)calloc(400, sizeof(char *));
    if (!temp_token_arr)
    {
        LOG("> couldn't create token array");
        return TOKEN_MEM_ALC_ERR;
    }
    LOG("> token_arr_was created");
    for (int pos = 0, i = 0; pos < buff_size;)
    {
        static int pos_shift = 0;
        pos_shift = detect_operation(buff, pos);
        if (pos_shift)
        {
            fprintf(stderr, "pos shift: %d\n", pos_shift);
            temp_token_arr[i] = buff + pos;
            i++;
            pos += pos_shift;
            continue;
        }
        pos++;
    }

    *token_arr = temp_token_arr;
    return 0;
}

int detect_operation(char *buff, int pos)
{
    int scanned = 0;
    double number = 0;

    if (buff[pos] == '(' || buff[pos] == ')')
    {
        fprintf(stderr, "detect sk\n");
        return sizeof(char);
    }
    else if (detect_operation(buff[pos]))
    {
        fprintf(stderr, "detect operation\n");
        return sizeof(char);
    }
    else if (sscanf(buff + pos, "%lf%n", &number, &scanned))
    {
        fprintf(stderr, "detect number\n");
        return scanned;

    }
    
    return 0;
}