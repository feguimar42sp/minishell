/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:27 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:21 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_unset(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		remove_env_var(argv[i++]);
	*current_exit_code() = 0;
}
