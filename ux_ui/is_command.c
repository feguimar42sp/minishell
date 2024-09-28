/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:41:29 by fernando          #+#    #+#             */
/*   Updated: 2024/09/26 15:51:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**environ;

int	is_command(char *pathname, char **argv, int block)
{
	s_built_in	*cmds;
	int			i;
	int			size;

	cmds = fill_commands();
	if (block < 0)
		return 0;
	i = 0;
	while (i < BUILT_INS)
	{
		size = ft_strlen(cmds[i].name) + 1;
		if (ft_strncmp(pathname, cmds[i].name, size) == 0)
		{
			to_pipe(block);
			cmds[i].func(argv);
			close_pipe(block);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_pwd(char **argv)
{
	char	*buffer;
	char	*cwd_ret;
	int		size;

	if (argv == NULL)
		return ;
	size = 100;
	cwd_ret = NULL;
	while (cwd_ret == NULL)
	{
		buffer = malloc(sizeof(char) * size);
		cwd_ret = getcwd(buffer, size);
		if (cwd_ret != NULL)
		{
			printf("%s\n", buffer);
			free(buffer);
			return ;
		}
		free(buffer);
		size = size * 2;
		if (size > 1073741820)
		{
			printf("Unable to allocate memory for PWD\n");
			return ;
		}
	}
}

void	ft_export(char **argv)
{
	int		i;

	if (argv == NULL)
		return ;
	i = 0;
	while (environ[i] != NULL)
	{
		printf("declare -x %s\n", environ[i]);
		i++;
	}
}

void	ft_cd(char **argv)
{
	change_dir(argv[1]);
}

void	ft_exit_cmd(char **argv)
{
	if (argv == NULL)
		return ;
	exit(2);
}

s_built_in	*fill_commands(void)
{
	s_built_in	*ret;

	ret = malloc(sizeof(s_built_in) * BUILT_INS );
	ret[0].name = ft_strdup("cd");
	ret[1].name = ft_strdup("pwd");
	ret[2].name = ft_strdup("export");
	ret[3].name = ft_strdup("exit");
	ret[0].func = ft_cd;
	ret[1].func = ft_pwd;
	ret[2].func = ft_export;
	ret[3].func = ft_exit_cmd;
	return (ret);
}
