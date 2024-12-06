/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:00:12 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 16:00:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_operator(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (1);
	else if (ft_strcmp(str, "<") == 0)
		return (1);
	else if (ft_strcmp(str, ">") == 0)
		return (1);
	else if (ft_strcmp(str, "<<") == 0)
		return (1);
	else if (ft_strcmp(str, ">>") == 0)
		return (1);
	return (0);
}

int	is_str_quoted(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[0] == '\'' && str[len] == '\'')
		return (1);
	else if (str[0] == '\"' && str[len - 1] == '\"')
		return (1);
	return (0);
}

void	ft_lexer(t_args_lst **split)
{
	t_args_lst	*ptr;

	ptr = *split;
	while (ptr)
	{
		if (is_operator(ptr->arg))
			ptr->type = operators;
		if (is_str_quoted(ptr->arg) == 1)
			ptr->is_quoted = true;
		ptr = ptr->next;
	}
}
