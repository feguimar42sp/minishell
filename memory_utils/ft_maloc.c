/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:39:16 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 17:32:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_maloc(size_t size, const char *name)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error();
	add_to_mem_list(name, ptr);
	return (ptr);
}
