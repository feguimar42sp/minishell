/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:51 by fernando          #+#    #+#             */
/*   Updated: 2024/10/07 20:16:55 by sabrifer         ###   ########.fr       */
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

// added a linked list to store the environment variables for ease of use	
typedef struct s_envp_lst
{
  char	*var;
  char	*value;
  struct s_envp_lst *next;
}	t_envp_lst;

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
void		execute_line(char *line);
void    execute_command(char *command, int block);
int			call_program(char *pathname, char **argv, char **envp, int block);
int			search_in_path(char *pathname, char **argv, char **envp, int block);
char		*get_dir(void);
char		*get_user_prompt(void);
int			is_command(char *pathname, char **argv, int block);
void		change_dir(char *path);
void		ft_exit(void);
pid_t		ft_getpid(void);
pid_t		*parent_pid(void);
void		treat_command(char **command);
void		check_single_quote(char **command);
void		check_double_quote(char **command);
int			count_char(char **command, char c);
void		expand_env_var(char **command);
void		replace_char(char **command, char old, char new);
void		treat_quotes(char **command);
void		replace_string(char **command, char **split);
int			run_from_root(char *pathname, char **argv, int block);
void		ft_pwd(char **argv);
void		ft_exit_cmd(char **argv);
void		ft_export(char **argv);
void		ft_cd(char **argv);
int			*num_pipes(void);
s_built_in	*fill_commands(void);
t_pipe      **pipes(void);
void        to_pipe(int block);
void        close_pipe(int block);
void        *ft_malloc(size_t size, const char *name);
void        add_to_mem_list(const char *name, void *ptr);
t_mem_node  **mem_list();
void        ft_free(void *ptr);

// function to store environment variable in a linked list
t_envp_lst	*store_envp(char **envp)
#endif
