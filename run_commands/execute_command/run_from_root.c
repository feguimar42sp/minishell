/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_from_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:44 by fernando          #+#    #+#             */
/*   Updated: 2024/11/07 23:07:22 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_from_root(char *pathname, char **argv, char** env_path)
{
	struct stat	fileStat;

	if (stat(pathname, &fileStat) == 0)
	{
		if (execve(pathname, argv, env_path) == -1)
			exit(EXIT_FAILURE);
	}
	return ;
}
