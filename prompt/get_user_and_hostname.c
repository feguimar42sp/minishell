/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_and_hostname.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:14:43 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 21:14:45 by sabrifer         ###   ########.fr       */
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

char	*get_user_and_hostname(void)
{
	char	*user;
	char	*hostname;
	char	*joined;

	user = get_user_prompt();
	hostname = get_hostname_prompt();
	joined = ft_strjoin(user, hostname);
	free(user);
	free(hostname);
	return (joined);
}
