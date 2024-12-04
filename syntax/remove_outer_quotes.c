/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_outer_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:45:22 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/03 21:37:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_syntax.h"
/*
char	*remove_quotes(char **str)
{
	char	*realloc_str;
	//int		len;
	int		new_len;

	//len = ft_strlen(*str);
	new_len = ft_strlen(*str) - 2;
	realloc_str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!realloc_str)
		return (NULL);
	ft_memcpy(realloc_str, (*str) + 1, new_len);
	ft_memcpy(realloc_str + new_len, "\0", 1);
	return (realloc_str);
}

void	check_quotes_and_remove(char **str)
{
	char	*temp;
	int		i;
	int		last;

	temp = NULL;
	i = 0;
	last = ft_strlen((*str)) - 1;
	if (((*str)[i] == '\'' && (*str)[last] == '\'') || ((*str)[i] == '\"'
			&& (*str)[last] == '\"'))
	{
		temp = remove_quotes(str);
		(*str) = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
}*/

void	remove_one_quote(char **str, int i)
{
	char	*temp;
	int		new_len;
	int		old_len;

	old_len = ft_strlen((*str));
	new_len = old_len - 1;
	temp = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!temp)
		return ;
	ft_memcpy(temp, (*str), i);
	strcpy(temp + i, (*str) + i + 1); // replace strcpy for FT_strcpy
	(*str) = ft_strdup(temp);
	free(temp);
	temp = NULL;
}

void	check_quotes_and_remove(char **str)
{
	bool	single_quotes;
	bool	double_quotes;
	//char	*temp;
	int		i;

	single_quotes = false;
	double_quotes = false;
	i = 0;
	//temp = NULL;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' && !double_quotes)
		{
			single_quotes = !single_quotes;
			remove_one_quote(str, i);
		}
		else if ((*str)[i] == '\"' && !single_quotes)
		{
			double_quotes = !double_quotes;
			remove_one_quote(str, i);
		}
		else
			i++;
	}
}

void	remove_outer_quotes(t_args_lst **args_lst)
{
	t_args_lst	*args;

	args = *args_lst;
	while (args)
	{
		check_quotes_and_remove(&args->arg);
		args = args->next;
	}
}
