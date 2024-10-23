#include "../minishell.h"

void	split_by_spaces(t_args_lst **split, char *str, int *i)
{
	int	len;
	int	start;

	len = 0;
	start = *i;
		//&& str[start] != '\'' && str[start] != '\"'
	while (str[start] != ' ' && str[start] != '\t'
		&& str[start] != '\0' && str[start] != '<'
		&& str[start] != '>' && str[start] != '|')
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
	if ((str[start] == '>' || str[start] == '<' || str[start] == '|')
		&& str[start] != '\0')
		split_by_redirects(split, str, i);
}