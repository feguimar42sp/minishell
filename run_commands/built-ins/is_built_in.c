/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s <rleite-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:33:14 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 15:49:19 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_built_in(char *pathname, char **argv, t_command *c, char **envp)
{
	t_built_in	*cmds;
	int			i;

	cmds = *fill_commands();
	i = 0;
	while (i < BUILT_INS)
	{
		if (ft_strcmp(pathname, cmds[i].name) == 0)
		{
			cmds[i].func(argv);
			free_split(&envp);
			free_split(&argv);
			free_args_list(args_list());
			free_t_command(c);
			free_commands(cmds);
			free_env_lst(env_vars_list(0));
			close_all();
			free_cmd_lst(*command_lst());
			exit (*current_exit_code());
		}
		i++;
	}
	free_commands(cmds);
	return (0);
}
