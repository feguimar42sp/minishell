/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/10 15:36:59 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		prompt = get_prompt();
		add_to_mem_list("prompt", prompt);
		ft_free(( void**)&line);
		line = readline(prompt);
		if (line == NULL)
			break;
		add_to_mem_list("line", line);
		add_history(line);

		// function to do lexing. convert a string into a set of tokens
		//ft_lexer(line);
		
		ft_free(( void**)&prompt);
	}
	free_all();
}
