/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:32:11 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/29 12:59:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "../libft/libft.h"
/* linked list from libft.h
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
t_list				**static_gc_list(void);
void				store_in_gc(void *address);
void				gc_free_all(void);
void				*gc_malloc(size_t size);

#endif
