/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_mem_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:41:15 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 17:31:05 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_mem_list(const char *name, void *ptr)
{
	t_mem_node	*new_node;

	new_node = malloc(sizeof(t_mem_node));
	if (!new_node)
		ft_error();
	new_node->name = ft_strdup(name);
	new_node->ptr = ptr;
	new_node->next = *mem_list();
	*mem_list() = new_node;
}
