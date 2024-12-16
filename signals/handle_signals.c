/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:56:29 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/16 17:39:10 by fernando         ###   ########.fr       */
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
	
	action.sa_handler = handle_sigint_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);

}

void	handle_sigint_exec(int sig)
{
	(void)sig;
	write(1, "\n", 1); // write a new line
	*running_loop() = 1;
}

void	handle_signals_exec(void)
{
	struct sigaction	action;
	// handles ctrl + \ by ignoring it
	handle_sigquit_signal();
	
	action.sa_handler = handle_sigint_exec;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);

}

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	exit(130);
}

void	handle_signals_heredoc(void)
{
	struct sigaction	action;
	// handles ctrl + \ by ignoring it
	handle_sigquit_signal();
	
	action.sa_handler = handle_sigint_heredoc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);

}