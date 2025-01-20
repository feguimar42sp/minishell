/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/19 21:32:07 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	script_files(char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd != -1)
	{
		close(STDIN_FILENO);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		write(STDERR_FILENO, "Error opening file: ", 20);
		write(STDERR_FILENO, av[1], ft_strlen(av[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(*current_exit_code());
	}
}