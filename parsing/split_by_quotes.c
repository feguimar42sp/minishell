/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:26 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/03 20:08:35 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	char	*temp;
	int		next_char;
	t_args_lst	*ptr;

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
	ptr = *split;
	while(ptr->next != NULL)
		ptr = ptr->next;
	check_quotes_and_remove(&(ptr->arg));
}