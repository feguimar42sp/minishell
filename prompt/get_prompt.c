/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:43:25 by fernando          #+#    #+#             */
/*   Updated: 2024/10/10 14:32:46 by fernando         ###   ########.fr       */
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

	if (getenv("USER") == NULL)
		user = ft_strdup("USER");
	else
		user = ft_strdup(getenv("USER"));
	if (getenv("HOSTNAME") == NULL)
		hostname = ft_strdup("HOSTNAME");
	else
		hostname = ft_strdup(getenv("HOSTNAME"));
	at = ft_strdup("@");
	temp = ft_strjoin(user, at);
	free(user);
	free(at);
	prompt = ft_strjoin(temp, hostname);
	free(temp);
	free(hostname);
	return (prompt);
}

char	*get_dir(void)
{
	char	*prompt;
	char	*dir;
	char	*ps;

	dir = getcwd(NULL, 0);
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
	free(user);
	free(colon);
	prompt = ft_strjoin(temp, dir);
	free(temp);
	free(dir);
	return (prompt);
}
