
#include "../minishell.h"

void	ft_lexer(t_args_lst **split)
{
	t_args_lst	*split_new;

	split_new = *split;
	while (split_new)
	{
		if (ft_strcmp(split_new->arg, "|") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, "<") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, ">") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, "<<") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, ">>") == 0)
			split_new->type = OPERATORS;
		split_new = split_new->next;
	}
}
