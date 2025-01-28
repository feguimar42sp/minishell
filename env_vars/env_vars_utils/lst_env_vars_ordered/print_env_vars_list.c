/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:54 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 00:45:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	print_env_vars_list(t_envp_lst *lst, char *line)
{
	while (lst != NULL)
	{
		if (line != NULL)
			printf("%s ", line);
		if (lst->value != NULL)
			printf("%s=\"%s\"\n", lst->var, lst->value);
		else
			printf("%s\n", lst->var);
		lst = lst->next;
	}
}
