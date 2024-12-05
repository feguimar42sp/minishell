/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:07:01 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/05 20:07:06 by sabrifer         ###   ########.fr       */
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
	int	len;

	len = 0;
	while (!ends_space_block(str[i + len]))
		len++;
	create_node(split, str, i, len);
}
