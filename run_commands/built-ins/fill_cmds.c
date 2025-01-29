/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:38:34 by fernando          #+#    #+#             */
/*   Updated: 2025/01/29 02:54:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_built_in	*fill_commands(void)
{
	static t_built_in	*ret;

	if (ret == NULL)
	{
		ret = malloc(sizeof(t_built_in) * BUILT_INS);
		ret[0].name = ft_strdup("cd");
		ret[1].name = ft_strdup("pwd");
		ret[2].name = ft_strdup("export");
		ret[3].name = ft_strdup("");
		ret[4].name = ft_strdup("env");
		ret[5].name = ft_strdup("echo");
		ret[6].name = ft_strdup("unset");
		ret[0].func = ft_cd;
		ret[1].func = ft_pwd;
		ret[2].func = ft_export;
		ret[3].func = ft_exit_cmd;
		ret[4].func = ft_env;
		ret[5].func = ft_echo;
		ret[6].func = ft_unset;
	}
	return (ret);
}
