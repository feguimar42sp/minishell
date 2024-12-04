/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:42:45 by fernando          #+#    #+#             */
/*   Updated: 2024/12/04 16:25:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_envp_lst	*var_dup(t_envp_lst *env_var)
{
	t_envp_lst	*new;

	new = malloc(sizeof(t_envp_lst));
	new->var = ft_strdup(env_var->var);
	new->value = ft_strdup(env_var->value);
	new->next = NULL;
	return (new);
}
