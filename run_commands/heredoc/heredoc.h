/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:14:21 by feguimar          #+#    #+#             */
/*   Updated: 2025/02/01 12:36:30 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../../minishell.h"

void	heredoc(t_command *command, t_args_lst **ptr, char *line);
void	heredoc_expand(t_command *command, t_args_lst **ptr, char *line,
			char *expan_line);
char	*expand_env_vars_heredoc(char *line);
int		strlen_expanded(char *line);
int		ft_envlen(char *line, int i);
void	expand_vars_to_string(char *dst, char *src);
char	*get_var_value_heredoc(char *line, int i);
int		not_end_env_var(char c);
char	*heredoc_gnl(int fd);
void	call_heredoc(t_command *command, t_args_lst **ptr);
int		expand_var_value(char *dst, int i, char *src, int *j);

#endif
