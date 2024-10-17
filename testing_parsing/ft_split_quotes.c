/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:52:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/14 21:41:13 by sabrifer         ###   ########.fr       */
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
	// printf("s[i] = [%c]\n", s[i]);
	return (i);
}

int	separator_by_length(char *s)
{
	int	closest;
	int	size;

	size = ft_strlen(s);
	closest = find_pos_strchr(s + 1, ' '); // -1
	if (find_pos_strchr(s + 1, '\'') < closest && find_pos_strchr(s + 1, '\'') != -1)
		closest = find_pos_strchr(s + 1, '\'');
	if (find_pos_strchr(s + 1, '\"') < closest)
		closest = find_pos_strchr(s + 1, '\"');
	if (closest > size)
		closest = size;
	return (closest);
}

int	separate_spaces(char *s, t_args_lst **split)
{
	int	i;
	int	len;
	int	size;

	size = ft_strlen(s);
	len = separator_by_length(s);
	printf("char found at pos %d = [%c]\n", len, s[len]);
	/*len = find_pos_strchr(s + 1, ' ');
	if (find_pos_strchr(s + 1, '\'') < len)
		len = find_pos_strchr(s + 1, '\'');
	else if (find_pos_strchr(s + 1, '\"') < len)
		len = find_pos_strchr(s + 1, '\"');*/
	len += 1;
	// if there's a quote after one or a few non-space was found,->
	// then check if there's another quote that matches it in the rest of the str
	// if there's a quote,
	// the goes back to the main function with the char 'quote'
	// as position,
	// so it can go back and enter another if that it meets the requirement to
	// separate it as a single string
	i = 0;
	create_node(split, s, i, len);
	i = i + len;
	return (i);
}

int	quotes_count(char *s)
{
	int		i;
	bool	s_quotes;
	bool	d_quotes;

	i = 0;
	s_quotes = false;
	d_quotes = false;
	while (s[i])
	{
		if (s[i] == '\'' && d_quotes == false)
			s_quotes = !s_quotes;
		else if (s[i] == '\"' && s_quotes == false)
			d_quotes = !d_quotes;
		i++;
	}
	if (s_quotes == true || d_quotes == true)
		return (0);
	return (1);
}
/*typedef struct	s_quotes
{
	int	single_count;
	int	double_count;
}		t_quotes;*/

t_args_lst	*ft_lst_split(char *s)
{
	t_args_lst	*split;
	int			i;
	int			value;
	bool		s_quotes;
	bool		d_quotes;

	split = NULL;
	i = 0;
	value = 0;
	s_quotes = false;
	d_quotes = false;
	if (!quotes_count(s))
	{
		printf("odd amount of quotes\n");
		return (NULL);
	}
	while (s[i] != '\0')
	{
		// ERROR if spaces only until a single or double quote or a space is found
		while (s[i] != '\'' && s[i] != '\"' && s[i] == ' ' && s[i] != '\0')
			i++;
		//printf("char at pos %d(i) in str = [%c]\n", i, s[i]);
		if (s[i] == '\'')
		{
			s_quotes = !s_quotes;
			value = separate_squotes(s + i, &split, &s_quotes);
		}
		else if (s[i] == '\"')
		{
			d_quotes = !d_quotes;
			value = separate_dquotes(s + i, &split, &d_quotes);
		}
		else if (s[i] != ' ' && s[i] != '\0')
			value = separate_spaces(s + i, &split);
		if (value >= ft_strlen(s))
			break ;
		i += value + 1;
	}
	printf("end of function ft_lst_split\n");
	return (split);
}

int	main(void)
{
	t_args_lst	*split;
	char		*str;
	int			i;

	// str = "echo        i \"sa'brina\"         'i 'ola'          FF'G\"G '  ola\"";
	// str = "echo i sa brina i ola FF G G ola";
	str = "'i'ola'  ff'gg\'\"\'";
	printf("[%s]\n", str);
	split = ft_lst_split(str);
	i = 0;
	while (split->next)
	{
		printf("node[%d] - split->arg:[%s]\n", i, split->arg);
		split = split->next;
		i++;
	}
}
