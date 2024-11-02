/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:53:39 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:28:05 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef MEM_UTILS_H
#define MEM_UTILS_h

void	add_to_mem_list(const char *name, void *ptr);
void	free_all(void);
void	ft_free(void **ptr);
void	*ft_maloc(size_t size, const char *name);
void	print_all_mem(void);

#endif