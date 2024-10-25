/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:38:34 by fernando          #+#    #+#             */
/*   Updated: 2024/10/24 20:43:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

s_built_in	*fill_commands(void)
{
	static s_built_in	*ret;

	if (ret == NULL)
	{
		ret = malloc(sizeof(s_built_in) * BUILT_INS );
		ret[0].name = ft_strdup("cd");
		ret[1].name = ft_strdup("pwd");
		ret[2].name = ft_strdup("export");
		ret[3].name = ft_strdup("exit");
		ret[0].func = ft_cd;
		ret[1].func = ft_pwd;
		ret[2].func = ft_export;
		ret[3].func = ft_exit_cmd;
	}
	return (ret);
}
