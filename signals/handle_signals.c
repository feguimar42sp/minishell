/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:56:29 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/26 12:02:01 by sabrifer         ###   ########.fr       */
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

	write(1, "\n", 1); // write a new line
	rl_on_new_line(); // start a new line, kind of starts new and
					  // ignores what was written before ctrl + c was pressed
	rl_replace_line("", 0); // because line was stored in the buffer
							// this one replaces what was stored with the text passed as argument
	rl_redisplay(); // display prompt again
	*current_exit_code() = 130;
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
