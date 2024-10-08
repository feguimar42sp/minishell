/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/09/23 23:34:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_envp_lst	*env_vars; // variable declared to store environment variables
	char	*line;
	char	*prompt;

	(void)ac;
	(void)av;
	env_vars = store_envp(envp); // get original envp and store in our own ->
								 // linked list to be able to delete and ->
								 // add new variables
	/* this while is here to be able to visualize our own envp:
	 * int i = 0;
	while (lst_env_args)
	{
		//printf("[node %d]\t[var = %s]\t[value = %s]\n", i, lst_env_args->var, lst_env_args->value);
		lst_env_args = lst_env_args->next;
		i++;
	}*/
//	line = malloc(sizeof(short));
//	if (line == NULL)
//		ft_error();
	while (1)
	{
		prompt = get_prompt();
		add_to_mem_list("prompt\n", prompt); // ??
		line = readline(prompt);
		add_history(line);
		check_single_quote(&line);
		check_double_quote(&line);
		execute_line(line, *env_vars);
		free(prompt);
	}
	//while (line != NULL)
	//{
	//	prompt = get_prompt();
	//	add_to_mem_list("prompt\n", prompt); // ??
	//	free(line);
	//	line = readline(prompt);
	//	add_history(line);
	//	check_single_quote(&line);
	//	check_double_quote(&line);
	//	execute_line(line);
	//	free(prompt);
	//}
	//free(prompt);
}
