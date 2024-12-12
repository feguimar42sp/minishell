/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 15:57:58 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef STATICS_H
#define STATICS_H

t_args_lst	**args_list(void);
t_envp_lst 	**env_vars_list(void);
t_mem_node	**mem_list(void);
int			*current_exit_code(void);
pid_t		*prog_pid(void);
pid_t		*running_loop(void);
t_envp_lst  **temp_env(void);
pid_t		*running_loop(void);

#endif
