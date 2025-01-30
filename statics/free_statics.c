/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_statics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:47:06 by fernando          #+#    #+#             */
/*   Updated: 2025/01/30 11:17:18 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void free_statics(void)
{
    int         i;
    t_built_in  *temp;

    free_args_list(args_list());
    free_t_command(*command_lst());
    *command_lst() = NULL;
    free_env_lst(env_vars_list());
    i = 0;
    temp = *fill_commands();
    while (i < 7)
    {
        free(temp[i].name);
    }
    free(*fill_commands());
}