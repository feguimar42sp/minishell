/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:48:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input(int *file, t_args_lst **ptr)
{
	if ((*ptr)->next == NULL)
	{
		ft_redirect_error();
		return ;
	}
	if ((*ptr)->next->type != string)
	{
		ft_redirect_error();
		return ;
	}
	if (*file != -1)
		close(*file);
	*file = open_file(ptr);
}
