/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:34:37 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 17:07:08 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(char **argv)
{
	char	*pwd;

	pwd = NULL;
	if (argv == NULL)
		return ;
	if (argv[1] != NULL)
	{
		write_human_stdout(" too many arguments",1);
		*current_exit_code() = 1;
		return ;
	}
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	*current_exit_code() = 0;
}
