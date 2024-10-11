/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:52:51 by sabrifer          #+#    #+#             */
/*   Updated: 2023/11/05 16:04:58 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_args_lst
{
	char				*arg; // single argument
	int					type; // type of argument - need to be implemented
	struct s_args_lst	*next;// points to the next argument
}	t_args_lst;

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

t_args_lst	*ft_lst_split(char const *s, char c)
{
	enum e_args	type;
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
	while (s[i])
	{
	  printf("inside while loop\n");
		if (s[i] == '\'')
		  in_squotes = true;
		else if (s[i] == '\"')
		  in_dquotes = true;

		if (!in_squotes && !in_dquotes)
		{
		  while (s[i] == c)
			i++;
		  j = 0;
		  while (s[i + j] != '\0' && s[i + j] != c)
			j++;
		  if (s[i] != '\0')
		  {
			new->arg = ft_substr(s, i, j);
			new->type = string;
			
			if (split == NULL)
			  split = new;
			else
			{
			  while (split->next)
			  {
				split = split->next;
			  }
				split->next = new;
			}
			i = i + j;
			in_dquotes = false;
			in_squotes = false;
		  }
		  else
			i++;
		}
	}
	return (split);
}

int	main(void)
{
  t_args_lst	*split;
  printf("1/2 function called\n");
  split = ft_lst_split("\"ec\"\'ho\' \"\"ol a\"\'    ioi\'\"", ' ');

  printf("2/2 function called\n");
  int i = 0;
  while (split)
  {
	printf("node[%d] - split->arg:[%s] - split->type:[%d]\n", i, split->arg, split->type);
	split = split->next;
	i++;
  }
}
