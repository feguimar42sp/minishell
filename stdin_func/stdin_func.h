/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:11:47 by fernando          #+#    #+#             */
/*   Updated: 2025/01/28 14:17:21 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_FUNC_H
# define STDIN_FUNC_H

# include "../minishell.h"

void	script_files(char **av);
char	*stdin_gnl(char *str);
char	*not_tty_gnl(int fd);
int		is_comment(char *str);
char	*to_single_line(char *str);

#endif
