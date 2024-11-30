/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:02 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/30 15:53:38 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **argv)
{
	int		i;
	int		end_line;

	i = 1;
	end_line = 1;
	if (argv[1] != NULL)
		if (ft_strncmp( argv[1], "-n", 3) == 0)
		{
			i = 2;
			end_line = 0;
		}
	while(argv[i] != NULL)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (end_line)
		printf("\n");
}