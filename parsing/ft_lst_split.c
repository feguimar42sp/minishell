#include "../minishell.h"

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	if (!unclosed_quotes(str))
		return (NULL);
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			split_by_redirects(&split, str, &i);
//		else if (str[i] == '$')
//			split_by_dollarsign(&split, str, &i);
		else
			split_by_spaces(&split, str, &i);
	}
	return (split);
}