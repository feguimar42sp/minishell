/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/23 15:54:41 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*line;
	char		*prompt;
	int			i;
	t_args_lst	*split = NULL;

	while (1)
	{
		prompt = get_prompt();
		add_to_mem_list("prompt", prompt);
		line = readline(prompt);
		if (line == NULL)
			break;
		add_to_mem_list("line", line);
		add_history(line);

		// function to do lexing. convert a string into a set of tokens
		//ft_lexer(line);
		printf("line received = [%s]\n", line);
		split = ft_lst_split(line);
		ft_lexer(&split);
		i = 0;
		while (split)
		{
			printf("node[%d] - split->arg:[%s] && split->type: [%d]\n", i, split->arg, split->type);
			split = split->next;
			i++;
		}
		//ft_free(( void**)&line);
		ft_free(( void**)&prompt);
	}
	free_all();
}
