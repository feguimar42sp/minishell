/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 18:52:19 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef RUN_COMMANDS_H
#define RUN_COMMANDS_H

void	add_word(t_args_lst **block, t_args_lst *ptr);
void	close_files(int *out_f, t_pipe **in_p);
char	**make_array(t_args_lst *lst);
int		open_file(t_args_lst **ptr);
void	run_curr_command(int *run, t_pipe **pipeline, t_args_lst **b, int t);
void	run_commands(void);
void	run_last_command(int *run, t_pipe **pipeline, t_args_lst **b, int t);
void	parse_redirect(int run, t_pipe *pipeline, t_args_lst **ptr, int t);
void	redirect_input(int run, t_args_lst **ptr, t_pipe *pipeline);
void 	redirect_output(int run, t_args_lst **ptr, t_pipe *pipeline, int t);
int		count_blocks(t_args_lst		*ptr);
void	make_pipes(t_pipe **pipeline);

#endif
