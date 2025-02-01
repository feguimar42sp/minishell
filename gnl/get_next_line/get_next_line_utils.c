/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:39:52 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 19:59:16 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*buffer;
	int		size;
	int		i;

	size = ft_strlen_gnl(src);
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		buffer[i] = src[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char)c;
	if (uc == 0)
		return ((char *)str + ft_strlen_gnl(str));
	while (str[i])
	{
		if (str[i] == uc)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	int		max_length;
	int		i;
	int		j;

	max_length = ft_strlen_gnl((char *)s1) + ft_strlen_gnl((char *)s2) + 1;
	i = 0;
	j = 0;
	new = (char *)malloc(max_length * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j + i] = s2[i];
		i++;
	}
	new[j + i] = '\0';
	return (new);
}
