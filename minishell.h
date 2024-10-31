/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:48:51 by fernando          #+#    #+#             */
/*   Updated: 2024/10/30 19:57:06 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUILT_INS 4

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef void			(*f_built_in)(char **);

typedef int				t_pipe[2];

// enum thingy to store the type of arguments the program might receive
typedef enum
{
	// command,
	string,
	operators,
	// filepaths,
	// env_var
}						e_args;

// linked list to store the arguments received
typedef struct s_args_lst
{
	char *arg;               // single argument
	e_args type;                // type of argument - need to be implemented
	struct s_args_lst *next; // points to the next argument
}						t_args_lst;

// added a linked list to store the environment variables for ease of use
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

void					ft_error(void);
void					free_all(void);
void					free_split(char ***spl);
char					*get_prompt(void);
char					*get_user_prompt(void);
void					*ft_maloc(size_t size, const char *name);
void					add_to_mem_list(const char *name, void *ptr);
t_mem_node				**mem_list(void);
void					ft_free(void **ptr);
void    				clear_args_list(t_args_lst **l);

// function to store environment variable in a linked list
t_envp_lst				*store_envp(char **envp);
void					print_all_mem(void);
void					load_env_vars(void);
t_envp_lst				**env_vars_list(void);
char					*ft_getenv(char *variable);

// function for doing the lexing of the line of arguments
void					ft_lexer(t_args_lst **split);

// parsing
void					create_node(t_args_lst **args_lst, const char *str, int start, int len);
void					split_by_quotes(t_args_lst **split, char *str, int *i);
void					split_by_redirects(t_args_lst **split, char *str, int *i);
void					split_by_spaces(t_args_lst **split, char *str, int i);
bool					unclosed_quotes(char *str);
t_args_lst				*ft_lst_split(char *str);
int						ft_strcmp(const char *s1, const char *s2);
t_args_lst 				**args_list(void);
void 					ft_quote_error(void);
int 					ends_space_block(char c);


//run commands
void 					run_commands(void);
void					add_word(t_args_lst **block, t_args_lst *ptr);
void 					parse_redirect(int *in_file, int *out_file, t_args_lst **ptr);
int 					is_output_to_file(char *s);
int 					is_input_from_file(char *s);
int 					is_input_from_heredoc(char *s);
void    				redirect_output(int *out_file, t_args_lst **ptr);
void					redirect_input(int *file, t_args_lst **ptr);
void    				ft_redirect_error(void);
void					run_curr_command(int *in_file, int *out_file, t_pipe **pipeline, t_args_lst **block);
char					**make_array(t_args_lst *lst);
void					set_process_io(int *in_f, int *out_f, t_pipe *in_p, t_pipe *out_p);
void					execute_command(char **command_line, char **env_path);
int						open_file(t_args_lst **ptr);
s_built_in				*fill_commands(void);
void					ft_cd(char **argv);
void					ft_exit_cmd(char **argv);
void					ft_export(char **argv);
void					ft_pwd(char **argv);
int						is_built_in(char *pathname, char **argv);
void					search_in_path(char *pathname, char **argv, char **envp);
void					run_from_root(char *pathname, char **argv, char** env_path);
void    				run_last_command(int *in_f, int *out_f, t_pipe *in_p, t_args_lst **b);
void    				set_last_process_io(int *in_f, int *out_f, t_pipe *in_p);
void					clear_args_list(t_args_lst **l);
void					close_files(int *in_f, int *out_f, t_pipe **in_p);




//debug
	void print_args_lst(t_args_lst	*ptr);
	void print_split(char **s);
#endif
