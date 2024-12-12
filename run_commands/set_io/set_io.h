/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:09:05 by fernando          #+#    #+#             */
/*   Updated: 2024/12/11 21:42:13 by feguimar         ###   ########.fr       */
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
int		is_env(char *s);
int		is_export(char *s);
void	output_to_file(int *file);
void	output_to_pipe(t_pipe *pipe);
void	set_last_process_io(int *out_f, t_pipe *in_p);
void	set_process_io(int *output_file, t_pipe *incomming_pipe, t_pipe *outgoing_pipe);

#endif