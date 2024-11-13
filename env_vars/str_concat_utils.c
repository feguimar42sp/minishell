/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_concat_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:37:56 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/13 12:38:21 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	*get_final_joined_str(char *str, char *prefix, char *prefix_value,
		int var_size)
{
	char	*final_res;
	int		len;

	len = ft_strlen(prefix) + var_size + 1;
	final_res = join_suffix(prefix_value, str + len);
	if (!final_res)
		return (NULL);
	return (final_res);
}
