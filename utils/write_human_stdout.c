/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_human_stdout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:43:16 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 18:28:54 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_human_stdout(char *str, int eol)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		if (eol)
			write(STDOUT_FILENO, "\n", 1);
	}
}
