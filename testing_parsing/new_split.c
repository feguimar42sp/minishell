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
#include <unistd.h>
#include <stdlib.h>

typedef struct s_args_lst
{
	char *arg;               // single argument
	int type;                // type of argument - need to be implemented
	struct s_args_lst *next; // points to the next argument
}			t_args_lst;

typedef struct s_quotes
{
	int		single_count;
	int		double_count;
}			t_quotes;

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
				return (len) ;
			j++;
		}
		len++;
	}
	return (len);
}

t_args_lst	*ft_lst_split(char *str)
{
	t_args_lst	*lst;
	int			i;
	int			j;

	lst = NULL;
	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{

		j = ft_strcspn(str + i, " \'\"\0");
		if (str[i] != '\0')
		{
			if ((str + i)[j] != '\0')
				j++;
			create_node(&lst, str, i, j);
			i = i + j;
		}
	}
	return (lst);
}

int	count_len_needed(char *str)
{
	static int	count;
	int			i;

	i = 0;
	// returns null if char does not exist in str
	if (ft_strcspn(str, "\'\""))
 // if it finds a single or double quote, separate the string by before the single
 // or double quotes, then store in node up to a character that is not space, single
 // or double quotes. and store in next node the remainder after
 // the space/singlequote/doublequotes
 //
 // if it does not find a single or double quote and it does not have spaces at the end,
 // store in the same node until it finds a space, single or double quote.
 // if it has spaces at the end then just copy up to the non-space characters, therefore
 // deleting the spaces
		if (str[i] != '\0' && str[i] != '\'' && str[i] != '\"')
		i++;
}

//void	create_node(t_args_lst **args_lst, const char *str, int start, int len)
t_args_lst	*split_final(t_args_lst **lst)
{
	t_args_lst	*split;
	t_args_lst	*new_lst;
	char		*str;

	split = NULL;
	new_lst = *lst;
	int i = 0;
	int j = 0;
	while (new_lst)
	{
		i = 0;
		while (new_lst->arg[j] != '\0' && new_lst->arg[j] != ' '
			&& new_lst->arg[j] != '\'' && new_lst->arg[j] != '\"')
		{
			j++;
		}
		create_node(&split, new_lst->arg, i, j);
	}
}

int	main(void)
{
	t_args_lst	*split;
	t_args_lst	*new_split;
	char		*str;
	int			i;
	//str = "echo \"p\"a\'\'\'\'\'ABCDE\"F\"G\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'ens\'";
	str = "echo bom dia 'mundo'";

	printf("[%s]\n", str);
	split = ft_lst_split(str);
	i = 0;
	while (split)
	{
		printf("node[%d] - split->arg:[%s]\n", i, split->arg);
		split = split->next;
		i++;
	}
	new_split = split_final(&split);
}
