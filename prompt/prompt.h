/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:51 by fernando          #+#    #+#             */
/*   Updated: 2024/12/06 21:19:46 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "../minishell.h"
# define GREEN "\x1b[32m"
# define COLOR_RESET "\x1b[0m"

char	*get_user_prompt(void);
char	*get_hostname_prompt(void);
char	*get_user_and_hostname(void);
char	*get_dir(void);
char	*get_prompt(void);
char	*change_color_prompt(char *prompt);

#endif
