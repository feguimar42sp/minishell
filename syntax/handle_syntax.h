/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_syntax.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:16:55 by sabrifer          #+#    #+#             */
/*   Updated: 2024/12/06 17:19:53 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SYNTAX_H
# define HANDLE_SYNTAX_H

# include "../minishell.h"

char	*remove_quotes(char **str);
void	check_quotes_and_remove(char **str);
void	remove_outer_quotes(t_args_lst **args_lst);

#endif
