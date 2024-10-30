/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:44:17 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 17:17:42 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_word(t_args_lst **block, t_args_lst *ptr)
{
	t_args_lst	*new;
	t_args_lst	*temp;

	new = (t_args_lst *)malloc(sizeof(t_args_lst));
	temp = *block;
	new->arg = ft_strdup(ptr->arg);
	new->type = string;
	new->next = NULL;
	if (temp == NULL)
		*block = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
