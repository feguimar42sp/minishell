/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:57:29 by fernando          #+#    #+#             */
/*   Updated: 2024/09/23 23:03:48 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	call_program(char *pathname, char **argv, char **envp, int block)
{
	int			ret;
	char		*temp;

	if (is_command(pathname, argv, block))
		return (1);
	if (pathname[0] == '/')
	{
		temp = ft_strdup(pathname);
		ret = run_from_root(temp, argv, block);
	}
	else
	{
		temp = ft_strjoin("/", pathname);
		ret = search_in_path(temp, argv, envp, block);
	}
	free(temp);
	return (ret);
}
