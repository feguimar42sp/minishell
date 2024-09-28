/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feguimar <feguimar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:44:17 by  feguimar         #+#    #+#             */
/*   Updated: 2023/11/03 17:25:46 by feguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	size;
	size_t	trim;
	char	*ret;
	char	*ret_f;

	if ((start >= (size_t)ft_strlen(s)) || (len == 0))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		trim = size;
	else
		trim = len;
	ret = ft_strdup(s + start);
	if (ret == NULL)
		return (ret);
	ret[trim] = '\0';
	ret_f = ft_strdup(ret);
	free(ret);
	return (ret_f);
}
