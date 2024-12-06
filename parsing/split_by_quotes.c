/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:26 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 16:01:29 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	char	*temp;
	int		next_char;

	next_char = (*i) + 1;
	temp = NULL;
	while (str[next_char] != '\0')
	{
		temp = ft_substr(str, next_char, ft_strlen(str) - next_char);
		if (quotes_are_balanced(temp))
		{
			if (str[next_char] == '<' || str[next_char] == '>'
				|| str[next_char] == '|' || str[next_char] == ' ')
			{
				free(temp);
				break ;
			}
		}
		free(temp);
		next_char++;
	}
	create_node(split, str, *i, next_char - (*i));
	*i = next_char + 1;
}
