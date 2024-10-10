/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:51 by fernando          #+#    #+#             */
/*   Updated: 2024/10/10 17:00:19 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
# define BUILT_INS 4

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef void (*f_built_in)(char **);

typedef int t_pipe[2];

// linked list to store the arguments received
typedef struct s_args_lst
{
	char				*arg; // single argument
	int					type; // type of argument - need to be implemented
	struct s_args_lst	*next;// points to the next argument
}	T_args_lst;

// enum thingy to store the type of arguments the program might receive
typedef enum e_args
{
	command,
	string,
	operators,
	filepaths,
	env_var	
}t_e_args;

// added a linked list to store the environment variables for ease of use	
typedef struct s_envp_lst
{
  char				*var;
  char				*value;
  struct s_envp_lst *next;
}				t_envp_lst;

typedef struct {
    char		*name;
    f_built_in	func;
} s_built_in;

typedef struct s_mem_node {
    char *name;
    void *ptr;
    struct s_mem_node *next;
} t_mem_node;

void		ft_error(void);
void		free_all(void);
void		free_split(char ***spl);
char		*get_prompt(void);
char		*get_user_prompt(void);
void        *ft_maloc(size_t size, const char *name);
void        add_to_mem_list(const char *name, void *ptr);
t_mem_node  **mem_list();
void        ft_free(void **ptr);

// function to store environment variable in a linked list
t_envp_lst	*store_envp(char **envp);
void		print_all_mem(void);
void		load_env_vars(void);
t_envp_lst  **env_vars_list(void);
char		*ft_getenv(char *variable);
#endif
