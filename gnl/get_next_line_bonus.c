/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:41:02 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/17 17:35:35 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	t_gnl_list			**temp;

	temp = &list;
	while (*temp)
	{
		if ((*temp)->fd == fd)
			break ;
		temp = &(*temp)->next;
	}
	if (!(*temp))
	{
		*temp = malloc(sizeof(t_gnl_list));
		if (!(*temp))
			return (NULL);
		(*temp)->fd = fd;
		(*temp)->line = NULL;
		(*temp)->next = NULL;
	}
	if (not_valid(fd, &(*temp)->line))
		return (NULL);
	return (get_next_line_bonus(fd, &(*temp)->line));
}

char	*get_next_line_bonus(int fd, char **line)
{
	int			read_data;

	if (!(*line))
	{
		(*line) = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!(*line))
			return (NULL);
		read_data = 0;
		while (read_data <= BUFFER_SIZE)
			(*line)[read_data++] = '\0';
		read_data = read(fd, (*line), BUFFER_SIZE);
		if (read_data <= 0)
		{
			free((*line));
			(*line) = NULL;
			return (NULL);
		}
		(*line)[read_data] = '\0';
	}
	return (get_line_(line, fd));
}

char	*get_line_from_file(char **line, int fd)
{
	char	*temp;
	char	*temp2;
	ssize_t	read_data;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_data = 1;
	while (read_data > 0)
	{
		read_data = read(fd, temp, BUFFER_SIZE);
		temp[read_data] = '\0';
		if (read_data <= 0)
			break ;
		temp2 = ft_gnl_strjoin(*line, temp);
		free(*line);
		*line = temp2;
		if (has_line(*line))
			break ;
	}
	free(temp);
	return (get_line_from_buffer(line));
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

int	not_valid(int fd, char **line)
{
	if (read(fd, NULL, 0) < 0)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (1);
	return (0);
}
