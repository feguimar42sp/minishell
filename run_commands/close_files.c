/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:07:12 by fernando          #+#    #+#             */
/*   Updated: 2024/11/27 19:33:22 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_files(int *out_f, t_pipe **in_p)
{
	if (*out_f != -1)
	{
		close(*out_f);
		*out_f = -1;
	}
	if (*in_p != NULL)
	{
		close((**in_p)[1]);
		close((**in_p)[0]);
	}
}
