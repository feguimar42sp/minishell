
#include "../minishell.h"

void	ft_lexer(t_args_lst **split)
{
	t_args_lst	*ptr;

	ptr = *split;
	while (ptr)
	{
		if (ft_strcmp(ptr->arg, "|") == 0)
			ptr->type = operators;
		else if (ft_strcmp(ptr->arg, "<") == 0)
			ptr->type = operators;
		else if (ft_strcmp(ptr->arg, ">") == 0)
			ptr->type = operators;
		else if (ft_strcmp(ptr->arg, "<<") == 0)
			ptr->type = operators;
		else if (ft_strcmp(ptr->arg, ">>") == 0)
			ptr->type = operators;
		ptr = ptr->next;
	}
}
