/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:50:37 by fernando          #+#    #+#             */
/*   Updated: 2024/09/24 00:37:47 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	expand_env_var(char **command)
{
	char	**split;
	int		i;
	char	*temp;

	temp = NULL;
	if ((*command)[0] == '\'')
		return ;
	if (ft_strchr(*command, '$') != NULL)
	{
		split = ft_split(*command, ' ');
		i = 0;
		while (split[i] != NULL)
		{
			if (split[i][0] == '$')
			{
				temp = getenv(&(split[i][1]));
				if (temp != NULL)
				{
					free(split[i]);
					split[i] = temp;
				}
			}
			i++;
		}
		replace_string(command, split);
		free_split(&split);
	}
}

void	replace_string(char **command, char **split)
{
	int		i;
	int		size;

	free(*command);
	size = 0;
	i = 0;
	while (split[i] != NULL)
	{
		size = size + ft_strlen(split[i]);
		i++;
	}
	*command = malloc(sizeof(char) * (size + 1));
	ft_bzero(*command, size + 1);
	i = 0;
	while (split[i] != NULL)
	{
		ft_strlcat(*command, split[i], size + 1);
		i++;
	}
}