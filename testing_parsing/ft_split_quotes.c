/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:52:51 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/13 12:35:12 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_args_lst
{
	char				*arg; // single argument
	int					type; // type of argument - need to be implemented
	struct s_args_lst	*next;// points to the next argument
}						t_args_lst;

enum e_args
{
	string,
	operators,
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
	new->type = string;
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

// função pra dar apenas update nos quotes boolean


// função para pegar o tamanho da string
int	count_length(const char *str, int i, char sep)
{
	int	j;

	j = i + 1;
	while (str[i + j] != '\0' && str[i + j] != sep)
		j++;
	return (j);
}

// char const *s
// int i to loop through str and mark beginning of each word
// int j to mark end of each word
// bool s_quotes and d_quotes
// space char
// t_args_lst to populate arg and type

t_args_lst	*ft_lst_split(char const *s, char c)
{
	t_args_lst	*split;
	t_args_lst	*new;
	char		*str;
	int		i;
	int		j;
	int		x;
	bool	in_squotes;
	bool	in_dquotes;

	split = NULL;
	i = 0;
	j = 0;
	x = 0;
	in_squotes = false; // not inside single quotes
	in_dquotes = false; // not inside double quotes
	while (s[i] != '\0')
	{
		while (s[i] != '\'' && s[i] != '\"' && s[i] == ' ')
			i++;
		if (s[i] == '\'')
		{
			in_squotes = !in_squotes; // this switches from one to another
		}
		if (in_squotes)
		{
			j = count_length(s, i, '\'');
			j++; // counting extra one for the the single quote char
			if (s[i] != '\0')
			{
				create_node(&split, s, i, j);
				i = i + j;
			}
		}
	}
	return (split);
}

int	main(void)
{
  t_args_lst	*split;
  char			*str;

  str = "echo        'i              i           kkkk '  o'la";
  printf("[%s]\n", str);
  split = ft_lst_split(str, ' ');

/*  int i = 0;
  while (split)
  {
	printf("node[%d] - split->arg:[%s] - split->type:[%d]\n", i, split->arg, split->type);
	split = split->next;
	i++;
  }*/
}
