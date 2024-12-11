/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:14 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/11 19:16:38 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **argv)
{
	char	*command;
	char	**env;

	env = split_env(argv);
	command = split_command(argv);
	clear_args_list(args_list());
	*args_list() = ft_lst_split(command);
	{
		ft_export(env);
		free_split(&env);
		free(command);
		ft_lexer(args_list());
		handle_environment_vars_expansion(args_list());
		remove_outer_quotes(args_list());
		run_commands();
		free_args_lst(args_list());
		exit(*current_exit_code());
	}
}
