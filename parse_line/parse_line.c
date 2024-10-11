/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:48:11 by fernando          #+#    #+#             */
/*   Updated: 2024/10/11 00:54:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void    parse_line(char **split_line)
{
    int             i;
    t_commandblock  *current_block;

    i = 0;
    while(split_line[i] != NULL)
    {
    	current_block = last_command_block();
        if (is_word(split_line[i]))
        	add_to_words(split_line[i], current_block);
        else
        {
        	parse_token(split_line, i, current_block);
        }
    }
}