/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:07:12 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 20:15:17 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_files(int *in_f, int *out_f, t_pipe **in_p)
{
	if (*in_f != -1)
	{
		close(*in_f);
		*in_f = -1;
	}
	if (*out_f != -1)
	{
		close(*out_f);
		*out_f = -1;
	}
	if (*in_p != NULL)
	{
		close((**in_p)[1]);
		close((**in_p)[0]);
		free(*in_p);
		*in_p = NULL;
	}
}
