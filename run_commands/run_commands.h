/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:12:19 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef RUN_COMMANDS_H
#define RUN_COMMANDS_H

void	add_word(t_args_lst **block, t_args_lst *ptr);
void	close_files(int *in_f, int *out_f, t_pipe **in_p);
char	**make_array(t_args_lst *lst);
int		open_file(t_args_lst **ptr);
void	run_curr_command(int *in_f, int *out_f, t_pipe **in_p, t_args_lst **b);
void	run_commands(void);
void	run_last_command(int *in_f, int *out_f, t_pipe *in_p, t_args_lst **b);
void	parse_redirect(int *in_file, int *out_file, t_args_lst **ptr);
void	redirect_input(int *file, t_args_lst **ptr);
void	redirect_output(int *out_file, t_args_lst **ptr);

#endif
