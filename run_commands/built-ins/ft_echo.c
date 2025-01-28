/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:02 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/28 16:52:52 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **argv)
{
	int		i;
	bool	new_line_flag;

	i = 1;
	new_line_flag = 1;
	if (argv[i] != NULL)
	{
		if (ft_strncmp(argv[i], "-n", 3) == 0)
		{
			i++;
			new_line_flag = 0;
		}
	}
	while (argv[i] != NULL)
	{
		write(STDOUT_FILENO, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (new_line_flag)
		write(STDOUT_FILENO, "\n", 1);
	exit(0);
}
