/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_tty_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:21:48 by fernando          #+#    #+#             */
/*   Updated: 2025/01/19 21:25:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char	*not_tty_gnl(int fd)
{
	char	*ret;

	ret = get_next_line(fd);
	if (ret == NULL)
		return (NULL);
	while((ft_strcmp(ret, "\n") == 0) || is_comment(ret))
	{
		free(ret);
		ret = get_next_line(fd);
		if (ret == NULL)
			return (NULL);
	}
	return (to_single_line(ret));
}

int	is_comment(char *str)
{
	while(str[0] == ' ')
		str++;
	return (str[0] == '#');
}

char	*to_single_line(char *str)
{
	if (str == NULL)
		return (str);
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}