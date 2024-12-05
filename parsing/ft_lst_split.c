/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:06:18 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/05 20:06:20 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			while (!ends_space_block(str[i]))
				i++;
		}
	}
	return (split);
}
