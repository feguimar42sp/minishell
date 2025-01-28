/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 19:05:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	convert_exit_value(char *c_value)
{
	int	current_value;

	current_value = ft_atoi(c_value);
	if (current_value == 0)
	{
		write_stderr(" numeric argument required", 1);
		return (2);
	}
	return ((short)current_value);
}

void	ft_exit_cmd(char **argv)
{
	if ((argv == NULL) || (argv[1] == NULL))
		exit(*current_exit_code());
	if (argv[0] && argv[1] && argv[2] == NULL)
		*current_exit_code() = convert_exit_value(argv[1]);
	else
	{
		write_stderr(" too many arguments", 1);
		exit(1);
	}
	write_human_stdout("exit", 1);
	exit(*current_exit_code());
}
