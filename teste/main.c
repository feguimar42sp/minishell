#include "../minishell.h"

int main(void)
{
    t_args_lst  *ptr;
    t_args_lst  **block;

    block = malloc(sizeof(t_args_lst **));
    *block = NULL;

    ptr = malloc(sizeof(t_args_lst));
    ptr->arg = "teste   ";
    ptr->type = string;
    add_word(block, ptr);
    add_word(block, ptr);
    add_word(block, ptr);
    add_word(block, ptr);
    print_args_lst(*block);
}
