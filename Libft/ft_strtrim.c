/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:40:28 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/15 17:03:35 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	y;

	if (!s1 || !set)
		return (NULL);
	y = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (y > 0 && ft_strchr(set, s1[y - 1]) != NULL)
		--y;
	if (i >= y)
		return (ft_strdup(""));
	res = ft_substr(s1, i, y - i);
	return (res);
}
