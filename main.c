/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 17:08:45 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*line;
	char		*prompt;

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
		clear_args_list(args_list());
		*args_list() = ft_lst_split(line);
		ft_lexer(args_list());
		run_commands();
		ft_free((void **)&prompt);
	}
	free_all();
}
