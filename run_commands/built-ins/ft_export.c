/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:35:14 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 18:38:29 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_export(char **argv)
{
	int	i;

	if (!valid_export_call())
		return ;
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
}

int	valid_export_call(void)
{
	t_args_lst *ptr;

	ptr = *args_list();
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->arg, "|") == 0)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
