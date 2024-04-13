/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:03:57 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:40 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	originlen;

	i = 0;
	len = ft_strlen(dst);
	originlen = ft_strlen(dst);
	if (dstsize == 0 || len >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && len < dstsize - 1)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (originlen + ft_strlen(src));
}
