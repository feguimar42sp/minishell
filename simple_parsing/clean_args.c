/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:10:01 by feguimar          #+#    #+#             */
/*   Updated: 2024/10/17 18:57:30 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_args(void)
{
	t_args_lst	*current;
	t_args_lst	*next;
	
	current = *parsed_line();
	while(current != NULL)
	{
		next = current->next;
		ft_free((void**)&(current->arg));
		ft_free((void**)&current);
		current = next;
	}
	*parsed_line() = NULL;
}