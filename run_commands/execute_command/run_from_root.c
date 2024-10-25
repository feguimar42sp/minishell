/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_from_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:44 by fernando          #+#    #+#             */
/*   Updated: 2024/10/24 21:50:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_from_root(char *pathname, char **argv, char** env_path)
{
	struct stat	fileStat;

	if (stat(pathname, &fileStat) == 0)
		execve(pathname, argv, env_path);
	return ;
}
