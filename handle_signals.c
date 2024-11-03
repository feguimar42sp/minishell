/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:56:29 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/03 13:57:06 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigquit_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sigint_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	get_prompt();
	return ;
}

void	handle_signals(void)
{
	struct sigaction	action;
	// handles ctrl + \ by ignoring it
	handle_sigquit_signal();

	// handles ctrl + c by doing nothing

	action.sa_handler = handle_sigint_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);

}
