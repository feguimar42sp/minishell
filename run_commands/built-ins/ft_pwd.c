/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:34:37 by fernando          #+#    #+#             */
/*   Updated: 2024/10/24 20:56:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(char **argv)
{
	char	*resizable_buffer;
	char	*valid_working_dir_return;
	int		characters_in_wd_string;

	if (argv == NULL)
		return ;
	characters_in_wd_string = 100;
	valid_working_dir_return = NULL;
	while (valid_working_dir_return == NULL)
	{
		resizable_buffer = malloc(sizeof(char) * characters_in_wd_string);
		valid_working_dir_return = getcwd(resizable_buffer, characters_in_wd_string);
		if ((valid_working_dir_return != NULL) || (characters_in_wd_string > 1073741820))
			break ;
		free(resizable_buffer);
		characters_in_wd_string = characters_in_wd_string * 2;
	}
	if (characters_in_wd_string > 1073741820)
		printf("Unable to allocate memory for PWD\n");
	else
		printf("%s\n", resizable_buffer);
	free(resizable_buffer);
	return ;
}
