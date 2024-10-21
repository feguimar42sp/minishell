/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_versionfinal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:28 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/21 14:34:29 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_args_lst
{
	char				*arg;
	int					type;
	struct s_args_lst	*next;
}						t_args_lst;

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
	if (temp == NULL)
		*args_lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	char	quote;
	int		len;
	int		start;

	len = 0;
	start = *i;
	if (str[start] == '\'' || str[start] == '\"')
		quote = str[start];
	start++;
	len++;
	while (str[start] != quote && str[start] != '\0')
	{
		start++;
		len++;
	}
	len += 1;
	create_node(split, str, *i, len);
	*i = *i + len;
}

void	split_by_redirects(t_args_lst **split, char *str, int *i)
{
	char	redirect;
	int		len;
	int		start;

	len = 0;
	start = *i;
	if (str[start] == '<')
	{
		while (str[start] == '<' && str[start] != '\0')
		{
			start++;
			len++;
		}
	}
	else if (str[start] == '>')
	{
		while (str[start] == '>' && str[start] != '\0')
		{
			start++;
			len++;
		}
	}
	else if (str[start] == '|')
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
}

void	split_by_spaces(t_args_lst **split, char *str, int *i)
{
	int	len;
	int	start;

	len = 0;
	start = *i;
	while (str[start] != ' ' && str[start] != '\t' && str[start] != '\''
		&& str[start] != '\"' && str[start] != '\0' && str[start] != '<'
		&& str[start] != '>' && str[start] != '|')
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
	if ((str[start] == '>' || str[start] == '<' || str[start] == '|') && str[start] != '\0')
	{
		split_by_redirects(split, str, i);
	}
}

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	int			start;
	int			len;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	start = 0;
	len = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[start] == '|')
			split_by_redirects(&split, str, &i);
		else
			split_by_spaces(&split, str, &i);
	}
	return (split);
}

int	main(int ac, char **av)
{
	t_args_lst	*split;
	t_args_lst	*new_split;
	char		*str;
	int			i;

	// str = "echo \"p\"a\'\'\'\'\'ABCDE\"F\"G\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'ens\'";
	// str = "echo \"Hello, World!\" < greetings.txt";
	//str = "command >> all_  > output.txt 2<<&1>";
	str = "ifconfig|grep \'inet \'|awk \'{print $2}\'";
	// str = av[1];
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
