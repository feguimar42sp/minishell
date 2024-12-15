/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:10 by fernando          #+#    #+#             */
/*   Updated: 2024/12/15 19:46:34 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_exit_cmd(char **argv)
{
	static int	i;

	i = 2;
	if (argv == NULL)
		return ;
	
	*current_exit_code() = i;
	printf("Exit\n");
	exit(2);
}
