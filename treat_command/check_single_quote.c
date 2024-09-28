/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_single_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:20:13 by fernando          #+#    #+#             */
/*   Updated: 2024/09/09 15:28:50 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_single_quote(char **command)
{
	int	count;

	count = count_char(command, '\'');
	if (count == 0)
		return ;
	if (count % 2)
		exit(2);
	replace_char(command, ' ', '\'');
}

void	replace_char(char **command, char old, char new)
{
	int	flag;
	int	i;

	i = 0;
	flag = -1;
	while ((*command)[i] != '\0')
	{
		if ((*command)[i] == new)
			flag = flag * -1;
		if (flag == 1)
			if ((*command)[i] == old)
				(*command)[i] = new;
		i++;
	}
}
