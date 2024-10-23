/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:14:39 by fernando          #+#    #+#             */
/*   Updated: 2024/08/25 23:17:52 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(void)
{
	t_mem_node	**head;
	t_mem_node	*current;
	t_mem_node	*to_free;

	print_all_mem();
	head = mem_list();
	current = *head;
	while (current != NULL)
	{
		if (current->ptr == NULL)
			;//printf("Pointer for '%s' already free.\n", current->name);
		else
		{
			//printf("Freeing: %s -> %p\n", current->name, current->ptr);
			free(current->ptr);
		}
		free(current->name);
		to_free = current;
		current = current->next;
		free(to_free);
	}
	*head = NULL;
}
