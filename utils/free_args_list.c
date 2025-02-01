/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s <rleite-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:51:21 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 14:09:00 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_lst(t_args_lst *node)
{
	if (!node)
		return ;
	free_lst(node->next);
	free(node->arg);
	free(node);
	node = NULL;
}

void	free_args_list(t_args_lst **args_lst)
{
	if (!args_lst || !*args_lst)
		return ;
	if (!*args_lst)
	{
		free(args_lst);
		return ;
	}
	free_lst(*args_lst);
	*args_lst = NULL;
}
