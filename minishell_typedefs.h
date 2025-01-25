/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:30:50 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 23:19:38 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

typedef void			(*f_built_in)(char **);

typedef int				t_pipe[2];

typedef enum
{
	string,
	operators,
}						e_args;

typedef struct s_args_lst
{
	char				*arg;
	e_args				type;
	bool				is_quoted;
	struct s_args_lst	*next;
}						t_args_lst;

typedef struct s_command
{
	t_args_lst			*comm;
	int					input;
	int					output;
	int					run;
	int					not_last;
	struct s_command	*next;
}						t_command;

typedef struct s_envp_lst
{
	char				*var;
	char				*value;
	struct s_envp_lst	*next;
}						t_envp_lst;

typedef struct
{
	char				*name;
	f_built_in			func;
}						s_built_in;

typedef struct s_mem_node
{
	char				*name;
	void				*ptr;
	struct s_mem_node	*next;
}						t_mem_node;

#endif
