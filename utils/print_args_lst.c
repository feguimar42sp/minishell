/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:41:37 by fernando          #+#    #+#             */
/*   Updated: 2025/01/20 12:50:07 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	print_args_lst(t_args_lst	*ptr)
{
    while(ptr)
    {
        write_stderr(ptr->arg, 1);
        if (ptr->is_quoted)
            write_stderr("is quoted", 1);
        if (ptr->type == string)
            write_stderr("string", 1);
        else
            write_stderr("operator", 1);
        ptr = ptr->next;
    }
}