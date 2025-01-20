/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_vars_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:54 by fernando          #+#    #+#             */
/*   Updated: 2025/01/20 10:11:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	print_env_vars_list(t_envp_lst *lst, char *line)
{
	while (lst != NULL)
	{
		if (line != NULL)
			printf("%s      ", line);
		printf("%s=%s\n", lst->var, lst->value);
		lst = lst->next;
	}
}
