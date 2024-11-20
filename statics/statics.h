/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2024/11/20 15:04:38 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef STATICS_H
#define STATICS_H

t_args_lst	**args_list(void);
t_envp_lst  **env_vars_list(void);
t_mem_node	**mem_list(void);
int			*exit_status(void);
int			*current_exit_code(void);
pid_t		*program_pid(void);
pid_t		*loop_pid(void);

#endif