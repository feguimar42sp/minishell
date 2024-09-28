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

int	main(void)
{
	char	*line;
	char	*prompt;

	line = malloc(sizeof(short));
	if (line == NULL)
		ft_error();
	while (line != NULL)
	{
		prompt = get_prompt();
		free(line);
		line = readline(prompt);
		add_history(line);
		check_single_quote(&line);
		check_double_quote(&line);
		execute_line(line);
		free(prompt);
	}
	free(prompt);
}
