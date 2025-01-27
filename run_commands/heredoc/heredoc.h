/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:14:21 by feguimar          #+#    #+#             */
/*   Updated: 2025/01/25 21:16:01 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#ifndef HEREDOC_H
#define HEREDOC_H

void	heredoc(t_command *command, t_args_lst **ptr);
void	heredoc_expand(t_command *command, t_args_lst **ptr);
char	*expand_env_vars_heredoc(char *line);
int		strlen_expanded(char *line);
int		ft_envlen(char *line, int i);
void	expand_vars_to_string(char *dst, char *src);
char	*get_var_value_heredoc(char *line, int i);
int		not_end_env_var(char c);
char	*heredoc_gnl(int fd);
void	call_heredoc(t_command *command, t_args_lst **ptr);

#endif