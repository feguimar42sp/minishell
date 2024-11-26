/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:30:01 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:43:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_args_lst **ptr)
{
	int	ret;

	ret = -1;
	if (ft_strcmp((*ptr)->arg, ">") == 0)
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	if (ft_strcmp((*ptr)->arg, ">>") == 0)
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_WRONLY | O_APPEND | O_CREAT, 0666);
	}
	if (ft_strcmp((*ptr)->arg, "<") == 0)
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_RDONLY);
	}
	return (ret);
}
