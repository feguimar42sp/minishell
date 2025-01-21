/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:00:40 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 15:52:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_H
# define ENV_VARS_H

# include "../minishell.h"
// functions to store environment variables in a linked list
t_envp_lst	*store_envp(char **envp);
void		add_to_lst(t_envp_lst **env_var, char *env);
int			find_pos_strchr(char *str, char c);

// functions to expand environment variables
void		handle_environment_vars_expansion(t_args_lst **arg_lst);
char		*parse_var_found(char *str);
char		*parse_var_found(char *str);
char		*get_var_value(char *var);

// function that help joining strings
char		*join_prefix_and_value(char *s1, char *s2);
char		*join_suffix(char *s1, char *s2);
char		*get_prefix(char *str);
char		*get_final_joined_str(char *str, char *prefix, char *prefix_value,
				int var_size);

char		*ft_getenv(char *variable);

// function to free env var list
void		env_free_lst(t_envp_lst *node);
void		free_env_lst(t_envp_lst **env_lst);

#endif
