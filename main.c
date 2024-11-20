/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/11/20 12:20:13 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*line;
	char		*prompt;

	line = malloc(1);
	while (line)
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
		printf("%i\n", WEXITSTATUS(*exit_status()));
	}
}
