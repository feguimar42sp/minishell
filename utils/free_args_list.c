/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:51:21 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/29 00:15:26 by fernando         ###   ########.fr       */
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
