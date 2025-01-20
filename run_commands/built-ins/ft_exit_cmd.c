/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/19 21:58:03 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	convert_exit_value(char *c_value)
{
	int	current_value;
	int	new_value;

	current_value = ft_atoi(c_value);
	if (current_value == 0)
	{
		//printf("ft_atoi error\n");
		return (2);
	}
	if (current_value >= 0 && current_value <= 255)
		return (current_value);
	new_value = current_value % 256;
	return (new_value);
}

void	ft_exit_cmd(char **argv)
{
	if (argv == NULL)
		return ;
	if (argv[0] && argv[1] && argv[2] == NULL)
		*current_exit_code() = convert_exit_value(argv[1]);
	else
		*current_exit_code() = 1;
	write_human_stdout("exit", 1);
	exit(*current_exit_code());
}
