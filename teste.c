#include "minishell.h"


#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_envp_lst	*env_vars;

	(void)ac;
	(void)av;
	line = NULL;
	env_vars = store_envp(envp);
	*env_vars_list() = env_vars;
	handle_signals();
	printf("%s\n", get_var_value_heredoc("$HOME sdfasdfasd", 0));
	free_env_lst(env_vars_list());
	rl_clear_history();

}
