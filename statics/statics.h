/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 16:03:17 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICS_H
# define STATICS_H

# include "../minishell.h"

t_args_lst	**args_list(void);
t_envp_lst	**env_vars_list(void);
t_mem_node	**mem_list(void);
int			*current_exit_code(void);

#endif
