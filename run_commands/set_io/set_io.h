/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 18:56:36 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#ifndef SET_IO_H
#define SET_IO_H

void	input_from_file(int *file);
void	input_from_pipe(t_pipe *pipe);
int		is_output_to_file(char *s);
int		is_input_from_file(char *s);
int		is_input_from_heredoc(char *s);
void	output_to_file(int *file);
void	output_to_pipe(t_pipe *pipe);
void	set_process_io(int run, t_pipe **pipeline, int t);

#endif