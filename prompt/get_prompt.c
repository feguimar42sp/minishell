/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:43:25 by fernando          #+#    #+#             */
/*   Updated: 2024/12/05 17:03:07 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_hostname_prompt(void)
{
	char	*prompt;
	char	*hostname;
	char	*temp;
	char	*colon;

	if (ft_getenv("SESSION_MANAGER") == NULL)
		hostname = ft_strdup("42SP");
	else
		hostname = ft_strdup(ft_getenv("SESSION_MANAGER"));
	temp = ft_substr(hostname, 6, 6);
	colon = ft_strdup(":");
	prompt = ft_strjoin(temp, colon);
	free(colon);
	free(temp);
	free(hostname);
	return (prompt);
}

char	*get_user_prompt(void)
{
	char	*prompt;
	char	*user;
	char	*at;

	if (ft_getenv("USER"))
		user = ft_strdup(ft_getenv("USER"));
	else
		user = ft_strdup("USER");
	at = ft_strdup("@");
	prompt = ft_strjoin(user, at);
	free(user);
	free(at);
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

char	*change_color_prompt(char *prompt)
{
	char	*temp;
	char	*new_prompt;

	temp = ft_strjoin(GREEN, prompt);
	new_prompt = ft_strjoin(temp, COLOR_RESET);
	free(temp);
	return (new_prompt);
}

char	*get_prompt(void)
{
	char	*prompt;
	char	*user;
	char	*hostname;
	char	*dir;
	char	*temp;

	user = get_user_prompt();
	hostname = get_hostname_prompt();
	temp = ft_strjoin(user, hostname);
	dir = get_dir();
	free(user);
	free(hostname);
	prompt = change_color_prompt(ft_strjoin(temp, dir));
	free(temp);
	free(dir);
	return (prompt);
}
