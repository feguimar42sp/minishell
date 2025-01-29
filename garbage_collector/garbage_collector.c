/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:29 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/29 12:57:25 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_list	**static_gc_list(void)
{
	static t_list	*gc;

	return (&gc);
}

void	store_in_gc(void *address)
{
	t_list	*gc_list;
	t_list	*current;

	gc_list = *static_gc_list();
	current = gc_list;
	if (gc_list == NULL)
		gc_list = ft_lstnew(address);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next->content = address;
	}
}

void	gc_free_all(void)
{
	ft_lstclear(&(*static_gc_list()), free);
}

void	*gc_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	store_in_gc(ptr);
	return (ptr);
}
