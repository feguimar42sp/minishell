/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:28 by fernando          #+#    #+#             */
/*   Updated: 2024/10/11 00:44:47 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	char	*prompt;
	char	**split_line;

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
		add_command_block();
		split_line = ft_split(line, ' ');
		parse_line(split_line);
		free_split(&split_line);
		ft_free(( void**)&prompt);
	}
	free_all();
}
