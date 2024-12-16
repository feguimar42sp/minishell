/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:25:10 by fernando          #+#    #+#             */
/*   Updated: 2024/12/15 20:23:59 by feguimar         ###   ########.fr       */
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
        printf("Failed to open file\n");
        return;
    }
	dump_from_file(in_f, (*file)[1]);
}
