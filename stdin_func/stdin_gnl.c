/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:16:52 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:46 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*stdin_gnl(char *str)
{
	if (isatty(STDIN_FILENO))
		return (readline(str));
	return (not_tty_gnl(STDIN_FILENO));
}
