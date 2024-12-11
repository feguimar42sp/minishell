/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:33:14 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 19:08:28 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_built_in(char *pathname, char **argv)
{
	s_built_in	*cmds;
	int			i;

	cmds = fill_commands();
	i = 0;
	while (i < BUILT_INS)
	{
		if (ft_strcmp(pathname, cmds[i].name) == 0)
		{
			cmds[i].func(argv);
			return (1);
		}
		i++;
	}
	return (0);
}
