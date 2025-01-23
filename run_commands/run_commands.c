/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:12:46 by fernando          #+#    #+#             */
/*   Updated: 2025/01/22 23:42:25 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_commands(void)
{
	t_args_lst		*ptr;
	t_args_lst		*block;
	t_pipe			*pipeline;
	int				run;
	int				total_blocks;

	ptr = *args_list();
	total_blocks = count_blocks(*args_list());
	make_pipes(&pipeline);
	char *tt;
	tt = malloc(10);
	run = 0;
	*running_loop() = 0;
	run = 0;
	while (ptr)
	{
		if (ptr->type == operators)
		{
			if (ft_strcmp(ptr->arg, "|") == 0)
				run++;
			else
				parse_redirect(run, pipeline, &ptr, total_blocks);
		}
		if (ptr)
			ptr = ptr->next;
	}
	ptr = *args_list();
	block = NULL;
	run = 0;
	while(ptr)
	{
		if (ptr->type == operators)
			{
				if (ft_strcmp(ptr->arg, "|") == 0)
				{
					run_curr_command(&run, &pipeline, &(block), total_blocks);
					block = NULL;
				}
			}
			else if (ptr->type == string)
			{
				add_word(&(block), ptr);
			}
			if (ptr)
				ptr = ptr->next;
	}
	run_last_command(&run, &pipeline, &(block), total_blocks);
	free(pipeline);
}

int	count_blocks(t_args_lst		*ptr)
{
	int	ret;

	ret = 1;
	while(ptr)
	{
		if (ptr->type == operators)
			if (ft_strcmp(ptr->arg, "|") == 0)
				ret++;
		ptr = ptr->next;
	}
	return (ret);
}

void	make_pipes(t_pipe **pipeline)
{
	int	total_blocks;
	int	i;

	total_blocks = count_blocks(*args_list());
	if (total_blocks == 1)
	{
		*pipeline = NULL;
		return ;
	}
	*pipeline = malloc(sizeof(t_pipe) * (total_blocks - 1));
	i = 0;
	while(i < (total_blocks - 1))
	{
		pipe((*pipeline)[i]);
		i++;
	}
}