/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:11 by fernando          #+#    #+#             */
/*   Updated: 2025/01/23 22:31:40 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	**command_lst(void)
{
	static t_command	*a;

	return (&a);
}

void push_command(t_command *new_command)
{
    t_command **head;

    head = command_lst();
    if (!new_command)
        return;
    new_command->next = *head;
    *head = new_command;
}

t_command *pop_command(void)
{
    t_command **head;
    t_command *removed_command;

    head = command_lst();
    if (!*head)
        return NULL;
    removed_command = *head;
    *head = (*head)->next;
    removed_command->next = NULL;
    return (removed_command);
}

t_command *new_command(int run)
{
    t_command *cmd;

    cmd = malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->run = run;
    cmd->next = NULL;
    cmd->comm = NULL;
    cmd->input = STDIN_FILENO;
    cmd->output = STDOUT_FILENO;
    return (cmd);
}

void free_t_command(t_command *cmd)
{
    if (!cmd)
        return;
    free_args_list(&(cmd->comm));
    free(cmd);
}