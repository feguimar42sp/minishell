/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:03:50 by fernando          #+#    #+#             */
/*   Updated: 2024/10/04 19:19:37 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(void *ptr)
{
	t_mem_node	*prev;
	t_mem_node	*to_free;
	t_mem_node	**current;

	prev = NULL;
	current = mem_list();
	while (*current != NULL)
	{
		if ((*current)->ptr == ptr)
		{
			to_free = *current;
			if (prev == NULL)
				*mem_list() = NULL;
			else
				prev->next = to_free->next;
			free(to_free->name);
			free(to_free->ptr);
			free(to_free);
			return ;
		}
		prev = *current;
		current = &(*current)->next;
	}
}
