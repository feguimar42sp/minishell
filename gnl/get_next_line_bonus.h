/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s <rleite-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:41:44 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/01 14:21:41 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	int					fd;
	char				*line;
	struct s_gnl_list	*next;
}					t_gnl_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_line_(char **line, int fd);
int		has_line(char *line);
char	*get_line_from_buffer(char **line);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *s1);
char	*get_line_from_file(char **line, int fd);
int		not_valid(int fd, char **line);
char	*get_next_line_bonus(int fd, char **line);

#endif
