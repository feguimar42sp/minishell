/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:00:00 by fernando          #+#    #+#             */
/*   Updated: 2024/12/13 16:34:07 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_args_list(t_args_lst **lst)
{
	t_args_lst	*curr;
	t_args_lst	*prev;

	curr = *lst;
	if (curr == NULL)
		return ;
	while (curr)
	{
		free(curr->arg);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	*lst = NULL;
}
