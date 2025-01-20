/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_human_stdout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:43:16 by fernando          #+#    #+#             */
/*   Updated: 2025/01/19 21:44:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    write_human_stdout(char *str, int eol)
{
    if (isatty(STDERR_FILENO))
    {
    write(STDOUT_FILENO, str, ft_strlen(str));
    if (eol)
        write(STDOUT_FILENO, "\n", 1);
        
    }
}