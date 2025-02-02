/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_signals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:29:23 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/02 19:03:06 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	close((*curr_cmd())->here[0]);
	close((*curr_cmd())->here[1]);
	close_all();
	free_t_command((curr_cmd()));
	free_cmd_lst(command_lst());
	free_args_list(args_list());
	free_env_lst(env_vars_list(0));
	exit(130);
}

void	handle_signals_heredoc(void)
{
	struct sigaction	action;

	handle_sigquit_signal();
	action.sa_handler = handle_sigint_heredoc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);
}
