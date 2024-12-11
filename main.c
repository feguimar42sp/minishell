/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:05:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/11 17:41:49 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	char		*prompt;
	t_envp_lst	*env_vars;
	t_pipe		app_link;
	pid_t		pid;
	char		*pid_str;

	pipe(app_link);
	handle_signals();
	pid = fork();
	if (pid == 0)
	{
		close(app_link[1]);
        pid_str = malloc(25);
        read(app_link[0], pid_str, 25);
        close(app_link[0]);
        *(prog_pid()) = ft_atoi(pid_str);
        free(pid_str);
		(void)ac;
		(void)av;
		line = NULL;
		env_vars = store_envp(envp);
		*env_vars_list() = env_vars;
		while (1)
		{
			prompt = get_prompt();
			line = readline(prompt);
			free(prompt);
			if (line)
			{
				add_history(line);
				clear_args_list(args_list());
				*args_list() = ft_lst_split(line);
				free(line);
				ft_lexer(args_list());
				handle_environment_vars_expansion(args_list());
				remove_outer_quotes(args_list());
				run_commands();
				free_args_lst(args_list());
			}
			else
			{
				printf("\nExit\n");
				break ; // deals with ctrl + d (sigquit)
			}
		}
		free_env_lst(env_vars_list());
		rl_clear_history();
	}
	else
	{
        close(app_link[0]);
		pid_str = ft_itoa(pid);
        write(app_link[1], pid_str, ft_strlen(pid_str));
		write(app_link[1], "\0", 1);
		free(pid_str);
        close(app_link[1]);
		waitpid(pid, NULL, 0);
    }
}