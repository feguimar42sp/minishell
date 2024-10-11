/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:44:15 by fernando          #+#    #+#             */
/*   Updated: 2024/10/10 23:44:20 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_commandblock  **command_block_list(void)
{
    static t_commandblock   *list;

    return (&list);
}