/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:54 by fernando          #+#    #+#             */
/*   Updated: 2024/12/04 16:25:00 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	print_env_vars_list(t_envp_lst *lst, char *line)
{
	while (lst != NULL)
	{
		printf("%s      %s=%s\n", line, lst->var, lst->value);
		lst = lst->next;
	}
}
