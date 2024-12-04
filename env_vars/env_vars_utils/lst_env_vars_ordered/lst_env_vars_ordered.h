/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_vars_ordered.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:40:09 by fernando          #+#    #+#             */
/*   Updated: 2024/12/04 16:25:16 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

#ifndef LST_ENV_VARS_ORDERED_H
# define LST_ENV_VARS_ORDERED_H

void    	list_env_vars_ordered(void);
t_envp_lst	*var_dup(t_envp_lst	*var);
void		add_in_place(t_envp_lst *new, t_envp_lst **lst);
int			compare_str(char *str1, char *str2);
void    	clear_env_vars_lst(t_envp_lst **lst);
void		print_env_vars_list(t_envp_lst *lst, char *line);

#endif