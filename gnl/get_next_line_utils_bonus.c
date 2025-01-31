/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:41:28 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/17 17:36:06 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line_(char **line, int fd)
{
	if (has_line(*line))
		return (get_line_from_buffer(line));
	else
		return (get_line_from_file(line, fd));
}

int	has_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line_from_buffer(char **line)
{
	char	*temp;
	char	*temp2;
	int		i;

	if (!has_line(*line))
	{
		temp = *line;
		*line = NULL;
		return (temp);
	}
	i = 0;
	while ((*line)[i] != '\n')
		i++;
	temp = ft_gnl_substr(*line, 0, i + 1);
	if (!temp)
		return (NULL);
	temp2 = ft_gnl_substr(*line, i + 1, 0);
	free(*line);
	if (temp2[0] == '\0')
	{
		free(temp2);
		temp2 = NULL;
	}
	*line = temp2;
	return (temp);
}

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s || !s[0])
		return (NULL);
	if (len == 0)
		return (ft_gnl_strdup(s + start));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && (j < len))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_gnl_strdup(char *s1)
{
	char		*str;
	size_t		i;
	size_t		len;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
