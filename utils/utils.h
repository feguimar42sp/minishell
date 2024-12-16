/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:01:47 by fernando          #+#    #+#             */
/*   Updated: 2024/12/15 20:28:26 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../minishell.h"

void	clear_args_list(t_args_lst **l);
void	free_split(char ***spl);
void	ft_error(void);
void	ft_quote_error(void);
void	ft_redirect_error(void);
void	dump_from_file(int in_file, int out_file);
int		compare_str(char *str1, char *str2);
void	wipe_pipe(t_pipe *in_file);
void	wipe_file(int fd);

#endif
