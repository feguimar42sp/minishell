/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:58:42 by sabrifer          #+#    #+#             */
/*   Updated: 2024/10/17 18:47:47 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexer(char *str)
{
  char	**split_by_spaces;

  split_by_spaces = ft_split(str, ' ');
  simple_parse(split_by_spaces);
}
