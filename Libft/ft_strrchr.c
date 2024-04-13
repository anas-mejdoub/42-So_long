/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:46:39 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/15 21:49:37 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;

	len = ft_strlen(str);
	while (len >= 0 && str[len] != (char)c)
		len--;
	if (len < 0 && (char)c != '\0')
		return (NULL);
	return ((char *)str + len);
}
// int main()
// {
// 	char *str = ft_strrchr("NULL",'P');
// 	// char *str2 = strrchr("NULL",'p');
// 	printf("%s\n", str);
// }