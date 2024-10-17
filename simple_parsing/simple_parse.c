/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:03:59 by feguimar          #+#    #+#             */
/*   Updated: 2024/10/17 19:25:16 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	simple_parse(char **str)
{
	t_args_lst	*current;
	int			i;

	i = 0;
	while(str[i] != NULL)
	{
		current = new_arg(str[i]);
		add_arg(current, parsed_line());
		i++;
	}
}

t_args_lst	*new_arg(char *str)
{
	t_args_lst	*ret;

	ret = ft_maloc(sizeof(t_args_lst), "bloco de argumento");
	ret->type = ft_token(str);
	ret->arg = ft_strdup(str);
	add_to_mem_list("argumento dentro do bloco", ret->arg);
	ret->next = NULL;
	return (ret);
}

void	pop_arg(t_args_lst	*arg, t_args_lst	**list)
{
	t_args_lst	*current;
	t_args_lst	*prev;

	current = *parsed_line();
	while(current != NULL)
	{
		if (current == arg)
		{
			if (current == *parsed_line())
				*parsed_line() = current->next;
			else
				prev = current->next;
			break ;
		}
		prev = current;
		current = current->next;
	}
	add_arg(arg, list);
}

void	add_arg(t_args_lst	*new, t_args_lst	**lst)
{
	t_args_lst	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

e_args	ft_token(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (operator);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (operator);
	if (ft_strncmp(str, ">", 2) == 0)
		return (operator);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (operator);
	if (ft_strncmp(str, "|", 2) == 0)
		return (operator);
	return (word);
}