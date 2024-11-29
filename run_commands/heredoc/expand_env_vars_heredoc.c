/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_vars_heredoc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:21:14 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/29 19:33:55 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_env_vars_heredoc(char *line)
{
	int		total_chars;
	int		i;
	char	*return_string;

	i = 0;
	total_chars = strlen_expanded(line);
	return_string = malloc(total_chars + 2);
	i = 0;
	expand_vars_to_string(return_string, line);
	return (return_string);
}