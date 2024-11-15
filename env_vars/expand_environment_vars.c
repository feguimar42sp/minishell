/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_environment_vars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:00:57 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/07 17:37:25 by sabrifer         ###   ########.fr       */
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
		else if (str[i] == '?')
		{
			len++;
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

char	*get_var_value(char *var)
{
	char	*value;

	if (ft_strcmp(var, "?") == 0)
	{
		value = ft_itoa(*current_exit_code());
		return (value);
	}
	value = ft_getenv(var);
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}
	
char	*join_prefix_and_value(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (!ret)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	free(s1);
	return (ret);
}

char	*join_suffix(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (!ret)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	free(s1);
	return (ret);
}

char	*expand_variable(char *str)
{
	char	*prefix;
	char	*prefix_value;
	char	*final_result;
	char	*value;
	char	*var;
	int		len_before;
	int		len_after;

	len_before = ft_strcspn(str, "$");
	prefix = ft_substr(str, 0, len_before);
	if (!prefix)
		return (NULL);
	printf("char: [%c]\n", str[len_before]);
//	if (str[len_before + 1] == ' ')
//		str[len_before] = -42;
	var = parse_var_found(str);
	value = get_var_value(var);
	prefix_value = join_prefix_and_value(prefix, value);
	if (!prefix_value)
		return (NULL);
	len_after = len_before + ft_strlen(var) + 1;
	final_result = join_suffix(prefix_value, str + len_after);
	if (!final_result)
		return (NULL);
	free(var);
	free (value);
	return (final_result);
}

char	*ft_expand(char **str, int *i)
{
	char	*value;
	char	*var;
	char	*expanded;
	int		new_len;
	int		pos;

	value = "THISISMEDATA";
	var = "data";
	new_len = strlen(*str) - strlen(var) + strlen(value);
	expanded = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!expanded)
		return (NULL);
	memcpy(expanded, *str, *i);
	memcpy(expanded + *i, value, strlen(value));
	pos = *i + strlen(var) + 1;
	strcpy(expanded + *i + strlen(value), *str + pos);
	if (*str)
		free(*str);
	return (expanded);
}
			
void	search_and_expand(char **str)
{
	int	i;

	while (*str[i])
	{
		if (*str[i] == '$')
		{
			if (*str[i + 1] == ' ')
				i++;
			else
			{
				
			}
		}
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
/*		while (ft_strchr(args->arg, '$'))
		{
			if (args->arg[0] == '\'')
				break ;
			args->arg = expand_variable(args->arg);
		}
		args = args->next;
	}*/
}
