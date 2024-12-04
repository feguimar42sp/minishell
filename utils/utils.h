/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:01:47 by fernando          #+#    #+#             */
/*   Updated: 2024/11/27 19:09:14 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef UTILS_H
#define UTILS_H

void	clear_args_list(t_args_lst **l);
void	free_split(char ***spl);
void	ft_error(void);
void 	ft_quote_error(void);
void    ft_redirect_error(void);
void	dump_from_file(int in_file, int out_file);
int 	compare_str(char *str1, char *str2);

#endif