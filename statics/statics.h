/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2025/01/29 01:49:39 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICS_H
# define STATICS_H

# include "../minishell.h"

t_args_lst	**args_list(void);
t_envp_lst	**env_vars_list(void);
t_mem_node	**mem_list(void);
int			*current_exit_code(void);
pid_t		*prog_pid(void);
pid_t		*running_loop(void);
t_envp_lst	**temp_env(void);
pid_t		*running_loop(void);
t_command	**command_lst(void);
pid_t       *last_pid(void);

#endif
