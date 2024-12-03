/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/11/02 11:09:05 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#ifndef PARSING_H
# define PARSING_H

void		create_node(t_args_lst **args_lst, const char *str, int start, int len);
void		ft_lexer(t_args_lst **split);
t_args_lst	*ft_lst_split(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		split_by_quotes(t_args_lst **split, char *str, int *i);
void		split_by_redirects(t_args_lst **split, char *str, int *i);
int 		ends_space_block(char c);
void		split_by_spaces(t_args_lst **split, char *str, int i);
bool		quotes_are_balanced(char *str);

#endif
