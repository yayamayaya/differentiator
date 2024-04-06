#include "tokenizator.h"

extern operation_t operations[OPERATIONS_NUMBER];

#define INITIAL_TOKEN_ARR_SIZE 100

void token_dump(const token_t *token_arr, const int token_arr_size);

int tokenizator(token_t **token_arr_ptr, const char *file_name)
{
    char *buff = NULL;
    int file_size = 0;

    int error = read_file(&buff, &file_size, file_name);
    if (error)
    {
        free(buff);
        return error;        
    }
    
    int token_arr_size = INITIAL_TOKEN_ARR_SIZE;
    token_t *token_arr = (token_t *)calloc(token_arr_size, sizeof(token_t));
    if (!token_arr)
    {
        LOG(">>> couldn't allocate memory for token array%40s\n", "[error]");
        free(buff);
        return MEM_ALC_ERR;
    }
    
    int token_num = 0;

    for (int pos = 0; pos < file_size;)
    {
        token_t token = detect_token(buff, &pos);
        if (token.data_type == SYNTAX_NOT_DET)        
        {
            free(token_arr);
            free(buff);
            return SYNTAX_ERR;
        }
        else if (token.data_type != 0)
        {
            token_arr[token_num] = token;
            token_num++;
            if (token_num == INITIAL_TOKEN_ARR_SIZE)
            {
                token_arr_size *= 2;
                token_arr = token_realloc(token_arr, INITIAL_TOKEN_ARR_SIZE * 2);
            }
        }
    }

    LOG("> total token count is %d\n", token_num);
    
    token_arr = token_realloc(token_arr, token_num + 1);
    *token_arr_ptr = token_arr;
    free(buff);

    token_dump(*token_arr_ptr, token_num);

    LOG("\n>> tokenization was done. Tokens count is %d\n", token_num + 1);
    return 0;
}

token_t *token_realloc(token_t *token_arr, int arr_size)
{
    assert(token_arr);
    assert(arr_size > 0);

    token_t *arr_holder = (token_t *)realloc(token_arr, arr_size * sizeof(token_t));
    if (!arr_holder)
    {
        LOG(">>> couldn't reallocate memory for token array%40s\n", "[error]");
        return token_arr;
    }
    
    return arr_holder;
}

token_t detect_token(char *buff, int *pos)
{
    token_t token = {0};

    if (isspace(buff[*pos]))
    {
        (*pos)++;
        LOG("current pos: %d, the rest is: %s\n", *pos, buff + *pos);
        return token;
    }
    
    if (buff[*pos] == 'x')
    {
        LOG(">> variable detected\n");
        LOG("current pos: %d, the rest is: %s\n", *pos, buff + *pos);
        token.data.variable = 'x';
        token.data_type = VARIABLE;
        (*pos)++;
        return token;
    }

    for (int op_num = 0; op_num < OPERATIONS_NUMBER; op_num++)
        if (!strncmp((operations + op_num)->operation, buff + *pos, (operations + op_num)->string_length))
        {
            LOG(">> operation '%s' detected <%d>\n", (operations + op_num)->operation, (operations + op_num)->operation_number);
            LOG("current pos: %d, the rest is: %s\n", *pos, buff + *pos);
            token.data.operation = (unsigned char)(operations + op_num)->operation_number;
            token.data_type = OPERATION;
            (*pos) += (operations + op_num)->string_length;
            return token;
        }    

    int n = 0;
    double number = 0;
    sscanf(buff + *pos, "%lf%n", &number, &n);
    if (n)
    {
        LOG(">> number %lf detected\n", number);
        LOG("current pos: %d, the rest is: %s\n", *pos, buff + *pos);
        (*pos) += n;
        token.data.number = number;
        token.data_type = NUMBER;
        return token;
    }

    LOG(">>> couldn't detect token, syntax error.%40s\n", "[error]");
    token.data_type = SYNTAX_NOT_DET;
    return token;
}

void token_dump(const token_t *token_arr, const int token_arr_size)
{
    assert(token_arr);
    assert(token_arr_size > 0);

    LOG("\n>> token dump start:\n");
    for (int pos = 0; pos < token_arr_size; pos++)
        switch (token_arr[pos].data_type)
        {
        case NUMBER:
            LOG("NUMBER: <%.2lf>\n", token_arr[pos].data.number);
            break;

        case OPERATION:
            LOG("OPERATION: <%#04x>\n", token_arr[pos].data.operation);
            break;
        
        case VARIABLE:
            LOG("VARIABLE: <%c>\n", token_arr[pos].data.variable);
            break;
        
        default:
            LOG(">>> fatal error%40s\n", "[error]");
            break;
        }
    
    LOG(">> token dump ended.\n\n");
    return;
}