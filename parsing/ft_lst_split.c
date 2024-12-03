#include "../minishell.h"

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	if (!quotes_are_balanced(str))
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			split_by_redirects(&split, str, &i);
		else
		{
			split_by_spaces(&split, str, i);
			while(!ends_space_block(str[i]))
				i++;
		}
	}
	add_to_mem_list("split_in_ft_lst_split", &split); // correto?
	return (split);
}
