/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:52:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/13 12:09:45 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_args_lst
{
	char *arg;               // single argument
	int type;                // type of argument - need to be implemented
	struct s_args_lst *next; // points to the next argument
}			t_args_lst;

enum		e_args
{
	STRING,
	OPERATOR,
};

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL || start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// função para criar um novo node
void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
{
	t_args_lst	*new;
	t_args_lst	*temp;
	enum e_args	type;

	new = (t_args_lst *)malloc(sizeof(t_args_lst));
	temp = *args_lst;
	new->arg = ft_substr(str, start, len);
	new->type = STRING;
	printf("string = [%s]\n", ft_substr(str, start, len));
	if (temp == NULL)
		temp = new;
	else
	{
		while (temp != NULL)
		{
			temp = temp->next;
		}
		temp = new;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (1)
	{
		if (*ret == (char)c)
			return (ret);
		if (*ret == '\0')
			break ;
		ret++;
	}
	return (NULL);
}

int	find_pos_strchr(char *str, char c)
{
	char *strchr_return ;
	strchr_return = ft_strchr(str, c);
	// find position of first ocurrence of char
	if (strchr_return != NULL)
		return (strchr_return - str);
	return (-1); // -1 because it can return any number starting from position 0
}

int	separate_dquotes(char *s, t_args_lst **split, bool *d_quotes)
{
	int	i;
	int	len;
	int	size;

	size = ft_strlen(s);
	// bool d_quotes is received as true, because it has found one quote
	// however it's missing its other half
	len = find_pos_strchr(s + 1, '\"');
	if (len != -1)
		*d_quotes = !(*d_quotes);
	i = 0;
	len += 1;
	if (len > size)
		len = size;
	if (s[i] != '\0')
	{
		create_node(split, s, i, len + 1);
		i = i + len;
	}
	return (i);
}

int	separate_squotes(char *s, t_args_lst **split, bool *s_quotes)
{
	int	i;
	int	len;
	int	size;

	size = ft_strlen(s);
	len = find_pos_strchr(s + 1, '\'');
	if (len != -1)
		*s_quotes = !(*s_quotes);
	i = 0;
	len += 1;
	if (len > size)
		len = size;
	if (s[i] != '\0')
	{
		create_node(split, s, i, len + 1);
		i = i + len;
	}
	//printf("s[i] = [%c]\n", s[i]);
	return (i);
}

int	separator_by_length(char *s)
{
	int		closest;

	closest = find_pos_strchr(s + 1, ' ');
	if (closest == -1)
		return (-1);
	if (find_pos_strchr(s + 1, '\'') < closest && find_pos_strchr(s + 1, '\'') != -1)
		closest = find_pos_strchr(s + 1, '\'');
	if (find_pos_strchr(s + 1, '\"') < closest && find_pos_strchr(s + 1, '\"') != -1)
		closest = find_pos_strchr(s + 1, '\"');

	return (closest);// this information will be used to know which function to go to ->
			 // spaces, single or double quotes
}

t_args_lst	*ft_lst_split(char *s)
{
	t_args_lst	*split;
	char		*str;
	int			i;
	int			j;
	int			end;

	split = NULL;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\'' && s[i] != '\"' && s[i] == ' ' && s[i] != '\0') // skip leading spaces
			i++;
		end = separator_by_length(s + i + 1);
		create_node(&split, s, i, end);
		i = i + end; // + 1; // pointing to the char after the space
	}
	return (split);
}

int	main(void)
{
	t_args_lst	*split;
	char		*str;

	str = "echo \"i'i \" ola";
	printf("[%s]\n", str);
	split = ft_lst_split(str);
	/*  int i = 0;
		while (split)
		{
		printf("node[%d] - split->arg:[%s] - split->type:[%d]\n", i, split->arg,
			split->type);
		split = split->next;
		i++;
		}*/
}
