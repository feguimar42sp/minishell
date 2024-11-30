/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:04:18 by feguimar          #+#    #+#             */
/*   Updated: 2024/11/27 19:13:51 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dump_from_file(int in_file, int out_file)
{
    char *buffer;
    ssize_t bytesRead;

	buffer = malloc(sizeof(char) * 1024);
	bytesRead = 1;
    while (bytesRead > 0)
	{
		bytesRead = read(in_file, buffer, sizeof(buffer));
        write(out_file, buffer, bytesRead);
    }
}