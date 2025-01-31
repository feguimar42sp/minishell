/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:06:18 by sabrifer          #+#    #+#             */
/*   Updated: 2025/01/29 00:21:36 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_nodes(t_args_lst **split, int node)
{
	char		*new_str;
	t_args_lst	*current;
	t_args_lst	*node_1;
	t_args_lst	*node_2;
	int			i;

	current = *split;
	i = 0;
	while (current && i < node)
	{
		current = current->next;
		i++;
	}
	if (!current || !current->next)
		return ;
	node_1 = current;
	node_2 = current->next;
	new_str = ft_strjoin(node_1->arg, node_2->arg);
	free(node_1->arg);
	node_1->arg = new_str;
	node_1->next = node_2->next;
	free(node_2->arg);
	free(node_2);
}

void	concat_if_export(t_args_lst **split)
{
	t_args_lst	*lst;
	int			i;

	lst = *split;
	i = 0;
	while (lst != NULL)
	{
		if (ft_strcmp(lst->arg, "export") == 0)
		{
			i++;
			break ;
		}
		i++;
		lst = lst->next;
	}
	join_nodes(split, i);
}

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	if (!quotes_are_balanced(str))
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			split_by_redirects(&split, str, &i);
		else
		{
			split_by_spaces(&split, str, i);
			while (!ends_space_block(str[i]))
				i++;
		}
	}
	concat_if_export(&split);
	return (split);
}
