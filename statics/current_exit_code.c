/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:13:34 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/07 15:14:33 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*current_exit_code(void)
{
    static int	exit_code = 0;

    return (&exit_code);
}
