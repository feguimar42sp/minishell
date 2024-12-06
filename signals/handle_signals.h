/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:58:39 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 16:07:25 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H

# include "../minishell.h"

void	handle_sigquit_signal(void);
void	handle_signals(void);
void	handle_sigint_signal(int sig);

#endif
