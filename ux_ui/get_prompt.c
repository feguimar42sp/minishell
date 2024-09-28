/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:43:25 by fernando          #+#    #+#             */
/*   Updated: 2024/08/26 16:19:02 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_user_prompt(void)
{
	char	*prompt;
	char	*hostname;
	char	*temp;
	char	*user;
	char	*at;

	user = ft_strdup(getenv("USER"));
	hostname = ft_strdup(getenv("HOSTNAME"));
	at = ft_strdup("@");
	temp = ft_strjoin(user, at);
	prompt = ft_strjoin(temp, hostname);
	free(temp);
	free(hostname);
	free(user);
	free(at);
	return (prompt);
}

char	*get_dir(void)
{
	char	*prompt;
	char	*dir;
	char	*ps;

	dir = ft_strdup(getcwd(NULL, 0));
	ps = ft_strdup(" $ ");
	prompt = ft_strjoin(dir, ps);
	free(dir);
	free(ps);
	return (prompt);
}

char	*get_prompt(void)
{
	char	*prompt;
	char	*user;
	char	*dir;
	char	*colon;
	char	*temp;

	user = get_user_prompt();
	dir = get_dir();
	colon = ft_strdup(":");
	temp = ft_strjoin(user, colon);
	prompt = ft_strjoin(temp, dir);
	free(user);
	free(dir);
	free(colon);
	free(temp);
	return (prompt);
}
