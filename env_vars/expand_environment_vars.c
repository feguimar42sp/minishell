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
	value = ft_strdup(ft_getenv(var));
	if (value == NULL)
		value = ft_strdup("");
	return (value);
}
	
char	*join_prefix_and_value(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (!joined)
		return (NULL);
	return (joined);
}

char	*join_suffix(char *s1, char *s2)
{
	char	*suffix;

	suffix = ft_strjoin(s1, s2);
	if (!suffix)
		return (NULL);
	return (suffix);
}

char	*get_prefix(char *str)
{
	char	*prefix;
	int		len;

	len = ft_strcspn(str, "$");
	prefix = ft_substr(str, 0, len);
	if (!prefix)
		return (NULL);
	return (prefix);
}

char	*get_final_joined_str(char *str, char *prefix, char *prefix_value, int var_size)
{
	char	*final_res;
	int		len;

	len = ft_strlen(prefix) + var_size + 1;
	final_res = join_suffix(prefix_value, str + len);
	if (!final_res)
		return (NULL);
	return (final_res);
}

char	*expand_variable(char *str)
{
	char	*prefix;
	char	*prefix_value;
	char	*final_result;
	char	*value;
	char	*var;
//	int		len_before;
//	int		len_after;

	prefix = get_prefix(str);
//	len_before = ft_strcspn(str, "$"); // checks for length before $ to create the substr
//	prefix = ft_substr(str, 0, len_before); // create the prefix before the expansion
//	if (!prefix) // check if substr worked
//		return (NULL);
	var = parse_var_found(str); // find the variable found with $ (example: $PATH, $USER, $?)
	value = get_var_value(var); // expands the variable and find its value
	prefix_value = join_prefix_and_value(prefix, value); // join prefix and the expanded variable
	free (value); // free var used
//	len_after = len_before + ft_strlen(var) + 1; // finds length of suffix after the expansion
	final_result = get_final_joined_str(str, prefix, prefix_value, ft_strlen(var));
//	len_after = ft_strlen(prefix) + ft_strlen(var) + 1; // finds length of suffix after the expansion
//	final_result = join_suffix(prefix_value, str + len_after); // join the prefix_value + suffix
//	if (!final_result) // check if join_function worked
//		return (NULL);
	free(prefix);
	free(prefix_value);
	free(var); // free var used
	return (final_result); // return whole string joined
}

void	handle_environment_vars_expansion(t_args_lst **arg_lst)
{
	t_args_lst	*args;

	args = *arg_lst;
	while (args)
	{
		while (ft_strchr(args->arg, '$'))
		{
			if (args->arg[0] == '\'')
				break ;
			args->arg = expand_variable(args->arg);
		}
		args = args->next;
	}
}
