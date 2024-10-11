/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:14:51 by fernando          #+#    #+#             */
/*   Updated: 2024/10/11 00:56:23 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    add_to_words(char *word, t_commandblock *current_block)
{
    // adiciona a palavra a lista, caso já haja outra adiciona um espaço e em seguida a palavra
    if (word || current_block)
        return ;
}