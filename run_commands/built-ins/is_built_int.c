/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:33:14 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 14:12:21 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_built_in(char *pathname, char **argv)
{
	t_built_in	*cmds;
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
	//criar funçao para dar free na variavel cmds/t_biult+in
	// 
	//
	return (0);
}
