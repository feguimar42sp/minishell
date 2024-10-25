#include "../minishell.h"

int ends_space_block(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '<'
		|| c == '>' || c == '|')
		return (1);
	return (0);
}

void	split_by_spaces(t_args_lst **split, char *str, int i)
{
	int	len;

	len = 0;
	while (!ends_space_block(str[i + len]))
		len++;
	create_node(split, str, i, len);
}