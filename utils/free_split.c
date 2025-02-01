/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s <rleite-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:51:06 by fernando          #+#    #+#             */
/*   Updated: 2025/02/01 15:12:58 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_split(char ***spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while ((*spl)[i] != NULL)
	{
		free((*spl)[i]);
		i++;
	}
	free(*spl);
}
