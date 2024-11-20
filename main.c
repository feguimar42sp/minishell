/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/11/20 16:45:27 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

int	main(void)
{
	char		*line;
	char		*prompt;

	handle_signals();
	*program_pid() = fork();
	if (*program_pid() != 0)
	{	
			line = malloc(1);
			*env_vars_list() = store_envp(environ);
			while (line)
			{		
				*loop_pid() = fork();
				if (*loop_pid() == 0)
				{
					prompt = get_prompt();
					free(line);
					line = readline(prompt);
					if (line == NULL)
						break ;
					add_history(line);
					clear_args_list(args_list());
					*args_list() = ft_lst_split(line);
					ft_lexer(args_list());
					run_commands();
					free(prompt);
				}
				else
					waitpid(*loop_pid(), exit_status(), 0);
			}
	}
	// else
	// 	waitpid(*program_pid(), exit_status(), 0);
}
