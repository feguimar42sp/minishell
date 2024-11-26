/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:39:44 by sabrifer          #+#    #+#             */
/*   Updated: 2024/11/08 01:42:41 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_free_split(char **arr)
{
	int	i;

	i = 0;
    if (!arr)
		return;
	while (arr[i])
    {
        free(arr[i]);
        i++;
    }
	free(arr);
}
