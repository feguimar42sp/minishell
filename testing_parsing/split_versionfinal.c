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

enum					e_args
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

/*void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	char	quote;
	int		len;
	int		start;

	len = 0;
	start = *i;
	if (str[start] == '\'' || str[start] == '\"')
	{
		quote = str[start];
		start++;
		len++;
	}
	while (str[start] != quote && str[start] != '\0')
	{
		start++;
		len++;
	}
	len += 1;
	printf("str[start] = %c and str[start + 1] = %c\n", str[start], str[start + 1]);
	create_node(split, str, *i, len);
	*i = *i + len;
}
*/

void	split_by_quotes(t_args_lst **split, char *str, int *i)
{
	bool	s_quotes = false;
	bool	d_quotes = false;
	int		len;
	int		start;

	len = 0;
	start = *i;
	while (str[start] != '\0')
	{
		if (str[start] == '\'' && d_quotes == false)
		{
			s_quotes = !s_quotes;
			start++;
			len++;
		}
		else if (str[start] == '\"' && s_quotes == false)
		{
			d_quotes = !d_quotes;
			start++;
			len++;
		}
		else if (s_quotes == false && d_quotes == false)
		{
			if (str[start] == ' ' || str[start] == '<'
				|| str[start] == '>' || str[start] == '|'
				|| str[start] == '\0')
			{
				break ;
			}
			else
			{
				start++;
				len++;
			}
		}
		else
		{
			start++;
			len++;
		}
	}
	//len += 1;
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
	redirect = str[start];
	start++;
	len++;
	while (str[start] == redirect)
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
}
/*
void	split_by_dollarsign(t_args_lst **split, char *str, int *i)
{
	
}*/
/*
void	split_by_spaces(t_args_lst **split, char *str, int *i)
{
	int	len;
	int	start;

	len = 0;
	start = *i;
	while (str[start] != ' ' && str[start] != '\t'
		&& str[start] != '\'' && str[start] != '\"'
		&& str[start] != '\0' && str[start] != '<'
		&& str[start] != '>' && str[start] != '|')
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
	if ((str[start] == '>' || str[start] == '<' || str[start] == '|')
		&& str[start] != '\0')
		split_by_redirects(split, str, i);
}*/

void	split_by_spaces(t_args_lst **split, char *str, int *i)
{
	int	len;
	int	start;

	len = 0;
	start = *i;
		//&& str[start] != '\'' && str[start] != '\"'
	while (str[start] != ' ' && str[start] != '\t'
		&& str[start] != '\0' && str[start] != '<'
		&& str[start] != '>' && str[start] != '|')
	{
		start++;
		len++;
	}
	create_node(split, str, *i, len);
	*i = *i + len;
	if ((str[start] == '>' || str[start] == '<' || str[start] == '|')
		&& str[start] != '\0')
		split_by_redirects(split, str, i);
}

bool	unclosed_quotes(char *str)
{
	int		i;
	bool	s_quotes;
	bool	d_quotes;

	i = 0;
	s_quotes = false;
	d_quotes = false;
	while (str[i])
	{
		if (str[i] == '\'' && d_quotes == false)
			s_quotes = !s_quotes;
		if (str[i] == '\"' && s_quotes == false)
			d_quotes = !d_quotes;
		i++;
	}
	if (s_quotes || d_quotes)
		return (false);
	return (true);
}

t_args_lst	*ft_lst_split(char *str)
{
	int			i;
	t_args_lst	*split;

	split = NULL;
	i = 0;
	if (!unclosed_quotes(str))
		return (NULL);
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			split_by_quotes(&split, str, &i);
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			split_by_redirects(&split, str, &i);
//		else if (str[i] == '$')
//			split_by_dollarsign(&split, str, &i);
		else
			split_by_spaces(&split, str, &i);
	}
	return (split);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_lexer(t_args_lst **split)
{
	t_args_lst	*split_new;

	split_new = *split;
	while (split_new)
	{
		if (ft_strcmp(split_new->arg, "|") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, "<") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, ">") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, "<<") == 0)
			split_new->type = OPERATORS;
		if (ft_strcmp(split_new->arg, ">>") == 0)
			split_new->type = OPERATORS;
		split_new = split_new->next;
	}
}


int	main(int ac, char **av)
{
	t_args_lst	*split;
	char		*str;
	int			i;

	//str = "echo \"p\"a\'\'\'\'\'ABCDE\"F\"G\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'ens\'";
	//str = "echo \"Hello, World!\" < greetings.txt";
	//str = "command >> all_  \"olaola\" | output.txt 2<<&1>";
	//str = "ifconfig|grep \'inet \'\"dfsdd|rfsd\"|awk \'{print $2}\'";
	// str = "\'inet \'|awk";
	//str = "\'inet \'>>awk";
	//str = "\'inet >>awk";
	// str = "echo "This will" 'be' wr'i't't'en" to file">"myfile"";
	//str = av[1];
	//str = "echo \"p\"a\'\'\'\'\'\'\"ra\"\'b\'\"\"\'\'\"\"\'\'\'éns\'";
	//str = "echo \"\"\"\"\"\"T\'u\'d\"o\"                      b\'\'\'\'\"e\"\'\'\"\"\"\"\"\"\'m\'\"\"\"\"\"\"\'?\'";
	//str = "echo \"List of files:\">files.txt | cat files.txt";
	//str = "echo \"\"\"\"\"\"T\'u\'d\"o b\"\'\'\'\'\"e\"\'\'\"\"\"\"\"\"\'m\'\"\"\"\"\"\"\'?\'";
	str = "e\'c\'h\"o\" kgf$?ghf";
	//str = " bo\'\'m\'\' \"d\"\'i\'\'\'\'\'\'\'\'\'\'\'\'\'\'a\'";

	printf("[%s]\n", str);
	split = ft_lst_split(str);

	ft_lexer(&split);
	i = 0;
	while (split)
	{
		printf("node[%d] - split->arg:[%s] && split->type: [%d]\n", i, split->arg, split->type);
		split = split->next;
		i++;
	}
}
