#include "../minishell.h"

void	split_by_redirects(t_args_lst **split, char *str, int *i)
{
	char	redirect;
	int		len;
	int		start;

	len = 0;
	start = *i;
	redirect = str[start];
	start++;
	len++;
	while (str[start] == redirect)
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
}