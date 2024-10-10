/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:07:33 by fernando          #+#    #+#             */
/*   Updated: 2024/10/10 14:12:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_mem(void)
{
	t_mem_node	*current;

	current = *mem_list();
	while (current != NULL)
	{
		printf("Printing  Memory block: %s, Pointer: %p\n", current->name, current->ptr);
		current = current->next;
	}
}
