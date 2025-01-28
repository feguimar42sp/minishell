/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:56:29 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/28 14:28:53 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigquit_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sigint_signal(int sig)
{
	(void)sig;
	if (!isatty(STDIN_FILENO))
		return ;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	*current_exit_code() = 130;
}

void	handle_signals(void)
{
	struct sigaction	action;

	handle_sigquit_signal();
	action.sa_handler = handle_sigint_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);
}

void	handle_sigint_exec(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	*running_loop() = 1;
}

void	handle_signals_exec(void)
{
	struct sigaction	action;

	handle_sigquit_signal();
	action.sa_handler = handle_sigint_exec;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);
}
