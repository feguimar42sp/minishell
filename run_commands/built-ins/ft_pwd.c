/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:34:37 by fernando          #+#    #+#             */
/*   Updated: 2024/12/03 10:17:48 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(char **argv)
{
	char	*pwd;

	if (argv != NULL)
		pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
}
