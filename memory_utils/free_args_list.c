/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:51:21 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/03 12:51:25 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_lst(t_args_lst *node)
{
	if (!node)
		return ;
	free_lst(node -> next);
	free(node->arg);
	free(node);
}

void	free_args_lst(t_args_lst **args_lst)
{
	if (!args_lst || !*args_lst)
		return ;
	free_lst(*args_lst);
	*args_lst = NULL;
}
