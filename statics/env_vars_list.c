/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:02:18 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 15:06:46 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envp_lst	**env_vars_list(int clear)
{
	static t_envp_lst	*list;

	if (clear == 1)
	{
		// free(list->var);
		// free(list->value);
		// free(list);
		list = NULL;
	}
	return (&list);
}
