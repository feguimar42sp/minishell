/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:28 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/17 20:55:49 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_args_lst
{
	char *arg;               // single argument
	int type;                // type of argument - need to be implemented
	struct s_args_lst *next; // points to the next argument
}			t_args_lst;

enum		e_args
{
	STRING,
	OPERATORS,
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

void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
{
	t_args_lst	*new;
	t_args_lst	*temp;
	enum e_args	type;

	new = (t_args_lst *)malloc(sizeof(t_args_lst));
	temp = *args_lst;
	new->arg = ft_substr(str, start, len);
	new->type = STRING;
	// printf("string = [%s]\n", ft_substr(str, start, len));
	if (temp == NULL)
		*args_lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	size_t	j;

	if (!s || !reject)
		return (0);
	len = 0;
	while (s[len])
	{
		j = 0;
		while (reject[j])
		{
			if (s[len] == reject[j])
				return (len);
			j++;
		}
		len++;
	}
	return (len);
}

int	split_by_quotes(t_args_lst **split, char *str, int i)
{
	char	quote;
	int		len;
	int		start;

	len = 0;
	start = i;
	if (str[start] == '\'')
		quote = '\'';
	else if (str[start] == '\"')
		quote = '\"';
	start++;
	while (str[start] != quote && str[start] != '\0')
	{
		start++;
		len++;
	}
	len += 2;
	create_node(split, str, i, len);
	return(i + len);
}

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	int			start;
	int			end;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	start = 0;
	end = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0') // skip space and tab
		{
			printf("spaces skipped\n");
			i++;
		}
		if (str[i] == '\'')
		{
			printf("single quote found\n");
			i = split_by_quotes(&split, str, i);
			printf("value of i 0[%d]\n", i);
		}
		else if (str[i] == '\"')
		{
			printf("double quote found\n");
			i = split_by_quotes(&split, str, i);
			printf("value of i 1[%d]\n", i);
		}
		else
		{
			end = 0;
			start = i;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && str[i] != '\"' && str[i] != '\0')
			{
				i++;
				end++;
			}
			create_node(&split, str, start, end);
		}
		if (str[i] == '\0')
			break ;
		printf("here\n");
	}
	return (split);
}

int	main(int ac, char **av)
{
	t_args_lst	*split;
	t_args_lst	*new_split;
	char		*str;
	int			i;

	//str = "echo \"p\"a\'\'\'\'\'ABCDE\"F\"G\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'ens\'";
	str = av[1];
	printf("[%s]\n", str);
	split = ft_lst_split(str);
	i = 0;
	while (split)
	{
		printf("node[%d] - split->arg:[%s]\n", i, split->arg);
		split = split->next;
		i++;
	}
}
