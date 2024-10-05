/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:33:24 by fernando          #+#    #+#             */
/*   Updated: 2024/10/04 18:51:51 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_malloc(size_t size, const char *name)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_error();
	}
	add_to_mem_list(name, ptr);
	return (ptr);
}
