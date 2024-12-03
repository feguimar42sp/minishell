/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:44 by fernando          #+#    #+#             */
/*   Updated: 2024/12/03 10:11:52 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd(char **argv)
{
	char	*old_pwd;
	char	*temp;
	char	*pwd;

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
	}
	free(old_pwd);
}
