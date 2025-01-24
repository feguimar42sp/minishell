/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 23:19:08 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef RUN_COMMANDS_H
#define RUN_COMMANDS_H

void	add_word(t_args_lst **block, t_args_lst *ptr);
void	close_files(int *out_f, t_pipe **in_p);
char	**make_array(t_args_lst *lst);
int		open_file(t_args_lst **ptr);
void	run_curr_command(t_command *command, t_pipe **pipeline, int not_last);
void	run_commands(void);
void	run_last_command(int *run, t_pipe **pipeline, t_args_lst **b, int t);
void	parse_redirect(t_command *command, t_args_lst **ptr);
void	redirect_input(t_command *command, t_args_lst **ptr);
void 	redirect_output(t_command *command, t_args_lst **ptr);
int		count_blocks(t_args_lst		*ptr);
void	make_pipes(t_pipe **pipeline);
void    call_list_commands(void);

#endif
