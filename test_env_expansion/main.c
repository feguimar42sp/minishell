/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:05:15 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:35 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_expand(char **str, int *i)
{
	char	*value;
	char	*var;
	char	*expanded;
	int		new_len;
	int		pos;

	value = "THISISMEDATA";
	var = "data";
	new_len = strlen(*str) - strlen(var) + strlen(value);
	expanded = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!expanded)
		return (NULL);
	memcpy(expanded, *str, *i);
	memcpy(expanded + *i, value, strlen(value));
	pos = *i + strlen(var) + 1;
	strcpy(expanded + *i + strlen(value), *str + pos);
	if (*str)
		free(*str);
	return (expanded);
}

int	main(void)
{
	char	*str;
	char	*temp;
	int		i;

	str = strdup("When copying $data from $data part of memory $ to another");
	temp = NULL;
	i = 0;
	printf("str = [[%s]]\n", str);
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == ' ')
				i++;
			else
			{
				temp = ft_expand(&str, &i);
				str = temp;
			}
		}
		i++;
	}
	printf("str = [[%s]]\n", str);
	free(str);
	return (0);
}
