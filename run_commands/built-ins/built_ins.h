/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 11:14:26 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

# include "../../minishell.h"

t_built_in	**fill_commands(void);
void		ft_cd(char **argv);
void		ft_exit_cmd(char **argv);
void		ft_export(char **argv);
void		ft_pwd(char **argv);
int			is_built_in(char *pathname, char **argv);
void		ft_echo(char **argv);
void		ft_env(char **argv);
void		ft_unset(char **argv);
int			has_equal_sign(char *str);
char		**split_env(char **argv);
char		*split_command(char **argv);
int			valid_export_call(void);
void		ft_export_run(char **argv);
void		ft_unset_run(char **argv);
void		ft_cd_run(char **argv);

#endif
