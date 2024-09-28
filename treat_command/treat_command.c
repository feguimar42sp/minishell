/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:47:27 by fernando          #+#    #+#             */
/*   Updated: 2024/09/09 17:02:00 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	treat_command(char **command)
{
	treat_quotes(command);
	expand_env_var(command);
}

void	treat_quotes(char **command)
{
	char	old;
	int		i;

	old = 0;
	if ((*command)[0] == '\'')
		old = '\'';
	if ((*command)[0] == '\"')
		old = '\"';
	if (old != 0)
	{
		i = 1;
		while ((*command)[i + 1] != '\0')
		{
			if ((*command)[i] == old)
				(*command)[i] = ' ';
			i++;
		}
	}
}
