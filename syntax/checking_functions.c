/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:32:58 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/26 22:50:53 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"

int	check_sequential_operators(t_args_lst **arg_lst)
{
	t_args_lst	*args;

	args = *arg_lst;
	while (args && args->next)
	{
		if (args->type == operators && args->next->type == operators)
			return (0);
		args = args->next;
	}
	return (1);
}

int	get_args_size(t_args_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	check_unique_operator(t_args_lst **arg_lst)
{
	t_args_lst	*args;
	int			lst_size;

	args = *arg_lst;
	lst_size = get_args_size(*arg_lst);
	if (lst_size == 1 && args->type == operators)
		return (0);
	return (1);
}

int	check_multiples(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '|')
		{
			if (str[i + 1] == '|' || str[i + 1] == '<' || str[i + 1] == '>')
				return (0);
		}
		if (str[i] == '<')
		{
			if (str[i + 1] == '|' || str[i + 1] == '>' || (str[i + 1] == '<'
					&& str[i + 2] == '<'))
				return (0);
		}
		if (str[i] == '>')
		{
			if (str[i + 1] == '|' || str[i + 1] == '<' || (str[i + 1] == '>'
					&& str[i + 2] == '>'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_multiple_operators_in_node(t_args_lst **arg_lst)
{
	t_args_lst	*args;

	args = *arg_lst;
	while (args)
	{
		if ((args->type == operators) && (!check_multiples(args->arg)))
			return (0);
		args = args->next;
	}
	return (1);
}
