/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:31:27 by feguimar          #+#    #+#             */
/*   Updated: 2024/12/12 21:47:46 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_unset_run(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		remove_env_var(argv[i++]);
}

void	ft_unset(char **argv)
{
	(void)argv;
}