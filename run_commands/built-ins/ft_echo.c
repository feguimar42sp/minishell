/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:02 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/19 21:49:55 by fernando         ###   ########.fr       */
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
	while(argv[i] != NULL)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (new_line_flag)
		write(1, "\n", 1);;
	*current_exit_code() = 0;
}