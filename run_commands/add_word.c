/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:44:17 by fernando          #+#    #+#             */
/*   Updated: 2024/10/23 19:44:30 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_word(t_args_lst **block, t_args_lst *ptr)
{
	create_node(block, ptr->arg, 0, ft_strlen(ptr->arg));
}