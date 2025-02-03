/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:07:01 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/03 20:03:19 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ends_space_block(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

void	split_by_spaces(t_args_lst **split, char *str, int i)
{
	int			len;
	t_args_lst	*ptr;

	len = 0;
	while (!ends_space_block(str[i + len]))
		len++;
	while ((!quotes_are_balanced(str + i + len)) && (str[len + i]!='\0'))
	{
		len++;
		while (!ends_space_block(str[i + len]))
			len++;
		if ((len) >= ft_strlen(str + i))
			break ;
	}
	create_node(split, str, i, len);
	ptr = *split;
	while(ptr->next != NULL)
		ptr = ptr->next;
	check_quotes_and_remove(&(ptr->arg));
}
