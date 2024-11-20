/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:56:29 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/20 16:12:08 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint_signal(int sig)
{
	if (sig == 2)
	{
		exit(2);
	}
}

void	handle_signals(void)
{
	struct sigaction	action;
	// handles ctrl + \ by ignoring it
	signal(SIGQUIT, SIG_IGN);
	// handles ctrl + c by doing nothing

	action.sa_handler = handle_sigint_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &action, NULL);

}
