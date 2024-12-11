/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:14 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 15:22:06 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	if (i == 1)
	{
		list_env_vars_ordered();
		return ;
	}
	i = 1;
	while (argv[i] != NULL)
		add_env_var(argv[i++]);
	*current_exit_code() = 0;
}
