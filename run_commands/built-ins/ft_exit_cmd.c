/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:10 by fernando          #+#    #+#             */
/*   Updated: 2024/11/07 15:24:33 by sabrifer         ###   ########.fr       */
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
	printf("value of i = [%d]\n", i);
	exit(i);
}
