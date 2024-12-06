/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environment_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 15:24:41 by sabrifer         ###   ########.fr       */
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

	value = NULL;
	if (ft_strcmp(var, "?") == 0)
	{
		value = ft_itoa(*current_exit_code());
		return (value);
	}
	if (ft_getenv(var))
		value = ft_strdup(ft_getenv(var));
	else
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

	var = parse_var_found((*str) + *i);
	value = get_var_value(var);
	new_len = ft_strlen(*str) - ft_strlen(var) + ft_strlen(value);
	expanded = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!expanded)
		return (NULL);
	ft_memcpy(expanded, *str, *i);
	ft_memcpy(expanded + *i, value, ft_strlen(value));
	pos = *i + strlen(var) + 1;
	ft_strcpy(expanded + *i + strlen(value), *str + pos);
	return (expanded);
}

void	update_quotes(char c, bool *single_quotes, bool *double_quotes)
{
	if (c == '\"' && *single_quotes == false)
		*double_quotes = !*double_quotes;
	if (c == '\'' && *double_quotes == false)
		*single_quotes = !*single_quotes;
}

void	handle_dollar_expansion(char **str, int index, bool *single_quotes)
{
	char	*temp;

	temp = NULL;
	if ((*str)[index] == '$' && !*single_quotes)
	{
		if ((*str)[index + 1] == '$')
			index++;
		else if ((*str)[index + 1] == '\"')
			(*str) = ft_strdup("");
		else if ((*str)[index + 1] != ' ' && (*str)[index + 1] != '\"')
		{
			temp = ft_expand(str, &index);
			(*str) = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
	}
}

void	search_and_expand(char **str)
{
	bool	single_quotes;
	bool	double_quotes;
	char	*temp;
	int		i;

	single_quotes = false;
	double_quotes = false;
	temp = NULL;
	i = 0;
	while ((*str)[i] && (*str)[i + 1])
	{
		update_quotes((*str)[i], &single_quotes, &double_quotes);
		handle_dollar_expansion(str, i, &single_quotes);
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
		{
			if (ft_strncmp(args->arg, "\"$\"", 4) == 0)
				break ;
			search_and_expand(&args->arg);
		}
		args = args->next;
	}
}
