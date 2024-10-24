#include "../minishell.h"

char	**lst_to_matrix(t_args_lst *lst)
{
	char	**strs;
	int	i;
	int	size;


	i = 0;
	size = ft_lstsize((t_list *)lst);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (strs == NULL)
	{
		printf("strs malloc ok\n");
		return (NULL);
	}
	while (lst)
	{
		strs[i] = ft_strdup(lst->arg);
		lst = lst->next;
		i++;
	}
	strs[i] = NULL;
	return (strs);
	
}
