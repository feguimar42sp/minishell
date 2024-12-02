/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:34:55 by fernando          #+#    #+#             */
/*   Updated: 2024/12/01 22:59:26 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#ifndef ENV_VARS_UTILS_H
# define ENV_VARS_UTILS_H

void		remove_first_env_var(void);
void 		remove_env_var(char *name);
t_envp_lst  *find_var_node(char *name);
t_envp_lst  *find_previous_var_in_list(char *name);
int 		is_valid_var(char **elements);
void 		add_env_var(char *var);
int 		is_valid_var(char **elements);
void    	list_env_vars_ordered(void);

#endif
