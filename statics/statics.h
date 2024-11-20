/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2024/11/20 11:49:36 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef STATICS_H
#define STATICS_H

t_args_lst	**args_list(void);
t_envp_lst  **env_vars_list(void);
t_mem_node	**mem_list(void);
int			*exit_status(void);

#endif