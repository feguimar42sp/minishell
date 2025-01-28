/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:44 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 01:40:23 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd_run(char **argv)
{
	char	*old_pwd;
	char	*temp;
	char	*pwd;

	if (argv[2] != NULL)
	{
		write_stderr(" too many arguments",1);
		*current_exit_code() = 1;
		return ;
	}
	temp = getcwd(NULL, 0);
	old_pwd = ft_strjoin("OLDPWD=", temp);
	free(temp);
	if (chdir(argv[1]) == 0)
	{
		add_env_var(old_pwd);
		temp = getcwd(NULL, 0);
		pwd = ft_strjoin("PWD=", temp);
		add_env_var(pwd);
		free(temp);
		free(pwd);
		*current_exit_code() = 0;
	}
	else
	{
		write_stderr(" No such file or directory", 1);
		*current_exit_code() = 1;
	}
	free(old_pwd);
}

void	ft_cd(char **argv)
{
	(void)argv;
}
