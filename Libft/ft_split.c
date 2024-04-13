/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:41:30 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/15 19:02:15 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static size_t	get_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**free2d(char **s, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**fill(char **res, int wc, char const *s, char c)
{
	int	i;

	i = 0;
	while (i < wc)
	{
		if (*s == c)
			s++;
		else
		{
			res[i] = ft_substr(s, 0, get_len(s, c));
			if (!res[i])
				return (free2d(res, i));
			s = s + get_len(s, c);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		wc;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	wc = count_word(s, c);
	res = malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill(res, wc, s, c));
}
