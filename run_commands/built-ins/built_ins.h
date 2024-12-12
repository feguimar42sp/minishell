/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 18:32:15 by feguimar         ###   ########.fr       */
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
void		ft_echo(char **argv);
void		ft_env(char **argv);
void		ft_unset(char **argv);
int 		has_equal_sign(char *str);
char		**split_env(char **argv);
char    	*split_command(char **argv);
int			valid_export_call(void);

#endif