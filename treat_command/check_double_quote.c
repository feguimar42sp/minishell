/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:20:13 by fernando          #+#    #+#             */
/*   Updated: 2024/09/09 15:28:37 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_double_quote(char **command)
{
	int	count;

	count = count_char(command, '\"');
	if (count == 0)
		return ;
	if (count % 2)
		exit(2);
	replace_char(command, ' ', '\"');
}

int	count_char(char **command, char c)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ptr = *command;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			count++;
		i++;
	}
	return (count);
}
