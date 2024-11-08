/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:00:40 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/02 21:05:04 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef ENV_VARS_H
# define ENV_VARS_H

// functions to store environment variables in a linked list
t_envp_lst	*store_envp(char **envp);
void		add_to_lst(t_envp_lst **env_var, char *env);
int			find_pos_strchr(char *str, char c);

// functions to expand environment variables
void		handle_environment_vars_expansion(t_args_lst **arg_lst);
char		*parse_var_found(char *str);

// functions implemented from library functions
char		*ft_getenv(char *variable);
size_t		ft_strcspn(const char *s, const char *reject);

// function to free env var list
void	env_free_lst(t_envp_lst *node);
void	free_env_lst(t_envp_lst **env_lst);

#endif
