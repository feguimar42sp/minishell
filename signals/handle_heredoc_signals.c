/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_signals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:29:23 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/28 14:29:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
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
