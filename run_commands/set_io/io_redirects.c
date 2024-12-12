/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:27:20 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 21:40:43 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_output_to_file(char *s)
{
	if (ft_strcmp(s, ">") == 0)
		return (1);
	if (ft_strcmp(s, ">>") == 0)
		return (1);
	return (0);
}

int	is_input_from_file(char *s)
{
	if (ft_strcmp(s, "<") == 0)
		return (1);
	return (0);
}

int	is_input_from_heredoc(char *s)
{
	if (ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}

int	is_env(char *s)
{
	if (ft_strcmp(s, "env") == 0)
		return (1);
	return (0);
}

int	is_export(char *s)
{
	if (ft_strcmp(s, "export") == 0)
		return (1);
	return (0);
}
