/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:24:02 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/01 16:24:04 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_commands(t_built_in *cmds)
{
	free(cmds[0].name);
	free(cmds[1].name);
	free(cmds[2].name);
	free(cmds[3].name);
	free(cmds[4].name);
	free(cmds[5].name);
	free(cmds[6].name);
	free(cmds);
}
