/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:30:01 by fernando          #+#    #+#             */
/*   Updated: 2024/10/24 01:22:57 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_args_lst **ptr)
{
	int	ret;

	if (ft_strcmp((*ptr)->arg, ">"))
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (ft_strcmp((*ptr)->arg, ">>"))
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_WRONLY | O_APPEND | O_CREAT);
	}
	if (ft_strcmp((*ptr)->arg, "<"))
	{
		(*ptr) = (*ptr)->next;
		ret = open((*ptr)->arg, O_RDONLY);
	}
	(*ptr) = (*ptr)->next;
	return (ret);
}
