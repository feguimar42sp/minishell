/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_prompt_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:15:55 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 21:15:58 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*change_color_prompt(char *prompt)
{
	char	*temp;
	char	*new_prompt;

	temp = ft_strjoin(GREEN, prompt);
	new_prompt = ft_strjoin(temp, COLOR_RESET);
	free(temp);
	return (new_prompt);
}
