/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:58:39 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 19:31:12 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H

# include "../minishell.h"

void	handle_sigquit_signal(void);
void	handle_signals(void);
void	handle_sigint_signal(int sig);
void	handle_sigint_exec(int sig);
void	handle_signals_exec(void);
void	handle_sigint_heredoc(int sig);
void	handle_signals_heredoc(void);
void	free_heredoc(void);

#endif
