/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/08 19:57:49 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_envp_lst	*env_vars; // variable declared to store environment variables
	char	*line;
	char	*prompt;

	env_vars = store_envp(__environ); // get original envp and store in our own ->
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
		prompt = get_prompt(); // this function is called to get the username to use as prompt							   // before the command. basically, to prompt the user
							   // It can also be replaced by just the char ">"
		add_to_mem_list("prompt\n", prompt); // ???
		line = readline(prompt); // sytem function called to get the line typed by the user
		add_history(line); // system function to store string received in command line history

		// the following two functions are used to ?
		// they replaces space chars for single or double quotes?
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
