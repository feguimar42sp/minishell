/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_tty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:10:23 by fernando          #+#    #+#             */
/*   Updated: 2024/12/16 13:13:49 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void reset_terminal_settings(void) 
{
    struct termios term;

    if (isatty(STDIN_FILENO)) 
    {
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag |= (ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
    }
}
