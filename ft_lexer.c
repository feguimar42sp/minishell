/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:58:42 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/10 23:01:09 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**place_quotes(char **str)
{
  
}

void	ft_lexer(char *str)
{
  char	**split_by_spaces;
  char	**split_by_args;

  split_by_spaces = ft_split(str, ' ');
  split_by_args = place_quotes(split_by_spaces);
}
