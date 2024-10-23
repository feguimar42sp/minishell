#include "../minishell.h"

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	bool	s_quotes = false;
	bool	d_quotes = false;
	int		len;
	int		start;

	len = 0;
	start = *i;
	while (str[start] != '\0')
	{
		if (str[start] == '\'' && d_quotes == false)
		{
			s_quotes = !s_quotes;
			start++;
			len++;
		}
		else if (str[start] == '\"' && s_quotes == false)
		{
			d_quotes = !d_quotes;
			start++;
			len++;
		}
		else if (s_quotes == false && d_quotes == false)
		{
			if (str[start] == ' ' || str[start] == '<'
				|| str[start] == '>' || str[start] == '|'
				|| str[start] == '\0')
			{
				break ;
			}
			else
			{
				start++;
				len++;
			}
		}
		else
		{
			start++;
			len++;
		}
	}
	//len += 1;
	create_node(split, str, *i, len);
	*i = *i + len;
}