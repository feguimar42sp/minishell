/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environment_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/03 21:31:44 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// /bin/echo $"HOM"E$USER ----> needs quotes removed

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
	pos = *i + ft_strlen(var) + 1;
	ft_strcpy(expanded + *i + ft_strlen(value), *str + pos);
	free(var);
	free(value);
	return (expanded);
}

void	update_quotes(char c, bool *single_quotes, bool *double_quotes)
{
	if (c == '\"' && *single_quotes == false)
		*double_quotes = !*double_quotes;
	if (c == '\'' && *double_quotes == false)
		*single_quotes = !*single_quotes;
}

// handles echo "$", " $ ", " $"
int	is_single_quote(char *str, int i)
{
	if (str[i] == '$')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			return (1);
		if (str[i - 1] == '\'' && str[i + 1] == '\'')
			return (1);
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (1);
	}
	return (0);
}

// two functions handles these examples:
// /bin/echo $"HOME"$USER
// /bin/echo $"HOME"
// /bin/echo $"42$"

int	is_inside_double_quotes(char *str, int pos)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			check = !check;
		if (i == pos && str[i] == '$' && check)
			return (1);
		i++;
	}
	return (0);
}

void	remove_dollar_sign(char **str, int i)
{
	char	*new_str;
	int		len;

	if (is_inside_double_quotes(*str, i))
		return ;
	len = ft_strlen(*str);
	new_str = (char *)malloc(len);
	if (!new_str)
		return ;
	memcpy(new_str, *str, i);
	memcpy(new_str + i, *str + i + 1, len - i);
	free(*str);
	*str = new_str;
}

int	handle_dollar_expansion(char **str, int index, bool *single_quotes)
{
	char	*temp;
	char	*original;

	temp = NULL;
	original = *str;
	if ((*str)[index] == '$' && !*single_quotes)
	{
		if (is_single_quote(*str, index))
			return (1);
		if ((*str)[index + 1] == '$')
			index++;
		else if ((*str)[index + 1] == '\"')
			remove_dollar_sign(str, index);
		else if ((*str)[index + 1] != ' ' && (*str)[index + 1] != '\"')
		{
			temp = ft_expand(str, &index);
			free(*str);
			(*str) = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
	}
	if (original != *str)
		return (0);
	return (1);
}

void	search_and_expand(char **str)
{
	bool	single_quotes;
	bool	double_quotes;
	int		i;

	single_quotes = false;
	double_quotes = false;
	i = 0;
	while ((*str)[i] && (*str)[i + 1])
	{
		update_quotes((*str)[i], &single_quotes, &double_quotes);
		if (handle_dollar_expansion(str, i, &single_quotes))
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
