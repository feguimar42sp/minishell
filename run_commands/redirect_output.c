/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:33:46 by fernando          #+#    #+#             */
/*   Updated: 2024/10/24 01:07:34 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_output(int *out_file, t_args_lst **ptr)
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
	if (*out_file != -1)
		close(*out_file);
	*out_file = open_file(ptr);
}
