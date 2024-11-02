/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/02 20:01:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*parse_var_found(char *str)
{
	char	*var_found;
	int		i;
	int		start;
	int		len;

	var_found = NULL;
	i = 0;
	start = 0;
	len = 0;
	while (str[i] != '$' && str[i] != '\0')
		i++;
	if (str[i] == '$')
	{
		i++;
		start = i;
		len++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i] != '\0')
		{
			len--;
			break ;
		}
		else if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '\0')
		{
			len--;
			break ;
		}
		len++;
		i++;
	}
	var_found = ft_substr(str, start, len);
	return (var_found);
}

void	handle_environment_vars_expansion(t_args_lst **arg_lst)
{
	char	*expanded_var;
	char	*var;
	char	*value;
	int		len_before;
	int		len_after;
	t_args_lst	*args;

	expanded_var = NULL;
	var = NULL;
	value = NULL;
	args = *arg_lst;
	while (args)
	{
		while (ft_strchr(args->arg, '$')) // the position needs to be saved
		{
			if (args->arg[0] == '\'')
				break ;
			// while here because it might have multiple $ in a single string
			len_before = ft_strcspn(args->arg, "$");
			expanded_var = ft_substr(args->arg, 0, len_before);
			var = parse_var_found(args->arg);
			value = ft_getenv(var);
			if (value == NULL)
				value = ft_strdup("");
			expanded_var = ft_strjoin(expanded_var, value);
			len_after = len_before + ft_strlen(var) + 1;
			expanded_var = ft_strjoin(expanded_var, args->arg + len_after);
			args->arg = expanded_var;
		}
		args = args->next;
	}
}
