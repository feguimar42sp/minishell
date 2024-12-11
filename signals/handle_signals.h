/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:58:39 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/11 18:27:50 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H

void	handle_sigquit_signal(void);
void	handle_signals(void);
void	handle_sigint_signal(int sig);

#endif
