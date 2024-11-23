/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environment_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/22 22:37:05 by sabrifer         ###   ########.fr       */
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
	if (!ft_strchr(str, '$'))
		return (NULL);
	start = (int)(ft_strchr(str, '$') - str) + 1;
	i = start;
	len++;
	while ((ft_isalnum(str[i]) || str[i] == '_') && str[i] != '\0')
	{
		len++;
		i++;
	}
	if (str[i] != '?')
		len--;
	var_found = ft_substr(str, start, len);
	return (var_found);
}

char	*get_var_value(char *var)
{
	char	*value;

	if (ft_strcmp(var, "?") == 0)
	{
		value = ft_itoa(*current_exit_code());
		return (value);
	}
	value = ft_strdup(ft_getenv(var));
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}

char	*ft_expand(char **str, int *i)
{
	char	*value;
	char	*var;
	char	*expanded;
	int		new_len;
	int		pos;

	var = parse_var_found(*str);
	value = get_var_value(var);
	new_len = strlen(*str) - strlen(var) + strlen(value);
	expanded = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!expanded)
		return (NULL);
	memcpy(expanded, *str, *i);
	memcpy(expanded + *i, value, strlen(value));
	pos = *i + strlen(var) + 1;
	strcpy(expanded + *i + strlen(value), *str + pos);
	return (expanded);
}

void	search_and_expand(char **str)
{
	bool	single_quotes;
	char	*temp;
	int		i;

	temp = NULL;
	single_quotes = false;
	i = 0;
	while ((*str)[i] && (*str)[i + 1])
	{
		if ((*str)[i] == '\'')
			single_quotes = !single_quotes;
		if ((*str)[i] == '$' && !single_quotes)
		{
			if ((*str)[i + 1] == '$' && (*str)[i + 1] != '\0')
				i++;
			else if ((*str)[i + 1] != ' ' && (*str)[i + 1] != '\"')
			{
				temp = ft_expand(str, &i);
				(*str) = ft_strdup(temp);
				free(temp);
				temp = NULL;
			}
		}
		i++;
	}
}

void	handle_environment_vars_expansion(t_args_lst **arg_lst)
{
	t_args_lst	*args;

	args = *arg_lst;
	while (args)
	{
		if (ft_strchr(args->arg, '$'))
			search_and_expand(&args->arg);
		args = args->next;
	}
}
