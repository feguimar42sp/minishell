/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:58:39 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/03 13:59:06 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H

void	handle_sigquit_signal(void);
void	handle_signals(void);

#endif
