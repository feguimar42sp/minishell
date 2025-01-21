/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2025/01/19 21:46:08 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input(t_pipe *file, t_args_lst **ptr)
{
	int	in_f;

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
	(*ptr) = (*ptr)->next;
	in_f = open((*ptr)->arg, O_RDONLY);
	if (in_f == -1)
	{
        write_stderr("Failed to open file", 1);
        //return;
    }
	dump_from_file(in_f, (*file)[1]);
}
