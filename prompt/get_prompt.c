/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:43:25 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 21:23:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_prompt(void)
{
	char	*temp;
	char	*dir;
	char	*prompt;
	char	*prompt_with_color;

	temp = get_user_and_hostname();
	dir = get_dir();
	prompt = ft_strjoin(temp, dir);
	prompt_with_color = change_color_prompt(prompt);
	free(temp);
	free(prompt);
	free(dir);
	return (prompt_with_color);
}
