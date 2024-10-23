#include "../minishell.h"

void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
{
	t_args_lst	*new;
	t_args_lst	*temp;

	new = (t_args_lst *)ft_lstnew(NULL);
	//new = (t_args_lst *)malloc(sizeof(t_args_lst));
	//new = 0;
	temp = *args_lst;
	new->arg = ft_substr(str, start, len);
	new->type = STRING;
	if (temp == NULL)
		*args_lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}
