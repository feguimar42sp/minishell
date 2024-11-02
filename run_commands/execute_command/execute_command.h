/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:20:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#ifndef EXECUTE_COMMAND_H
#define EXECUTE_COMMAND_H

void	execute_command(char **command_line, char **env_path);
void	run_from_root(char *pathname, char **argv, char** env_path);
void	search_in_path(char *pathname, char **argv, char **envp);

#endif