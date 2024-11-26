/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:17:17 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#ifndef BUILT_INS_H
#define BUILT_INS_H

s_built_in	*fill_commands(void);
void		ft_cd(char **argv);
void		ft_exit_cmd(char **argv);
void		ft_export(char **argv);
void		ft_pwd(char **argv);
int			is_built_in(char *pathname, char **argv);

#endif