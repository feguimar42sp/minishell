#include "../minishell.h"

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	int	next_quote;

	next_quote = (*i) + 1;
	while(str[next_quote] != '\0')
	{
		if (str[next_quote] == str[*i])
			break ;
		next_quote++;
	}
	if (str[next_quote] == '\0')
		ft_quote_error();
	else
		create_node(split, str, *i, next_quote - (*i) + 1);
	*i = next_quote + 1;
}
