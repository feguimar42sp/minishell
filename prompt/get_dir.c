/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:16:32 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 21:16:34 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_dir(void)
{
	char	*prompt;
	char	*dir;
	char	*ps;

	dir = getcwd(NULL, 0);
	ps = ft_strdup(" $ ");
	prompt = ft_strjoin(dir, ps);
	free(dir);
	free(ps);
	return (prompt);
}
