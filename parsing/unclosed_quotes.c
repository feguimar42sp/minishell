#include "../minishell.h"

bool	quotes_are_balanced(char *str)
{
	int		i;
	bool	s_quotes;
	bool	d_quotes;

	i = 0;
	s_quotes = false;
	d_quotes = false;
	while (str[i])
	{
		if (str[i] == '\'' && d_quotes == false)
			s_quotes = !s_quotes;
		if (str[i] == '\"' && s_quotes == false)
			d_quotes = !d_quotes;
		i++;
	}
	if (s_quotes || d_quotes)
		return (false);
	return (true);
}
