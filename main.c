/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 18:07:56 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	char		*prompt;

	(void)ac;
	(void)av;
	while (1)
	{
		prompt = get_prompt();
		add_to_mem_list("prompt", prompt);
		ft_free((void **)&line);
		line = readline(prompt);
		if (line == NULL)
			break ;
		add_to_mem_list("line", line);
		add_history(line);

		t_envp_lst *env_vars = store_envp(envp);
		*env_vars_list() = env_vars;
		clear_args_list(args_list());
		*args_list() = ft_lst_split(line);
		ft_lexer(args_list());
/*		t_envp_lst *temp = *env_vars_list();
		int	i = 0;
		while (temp)
		{
			printf("[node %d]\t[var = %s]\t[value = %s]\n", i, temp->var, temp->value);
			temp = temp->next;
			i++;
		}
*/		handle_environment_vars_expansion(args_list());
		run_commands();
		ft_free((void **)&prompt);
	}
	free_all();
}
