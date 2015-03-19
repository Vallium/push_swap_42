/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:56:26 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/11 12:56:13 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	wc(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++j;
			while (s[i] != c)
			{
				if (!s[i])
					return (j);
				++i;
			}
		}
		++i;
	}
	return (j);
}

static int	wl(const char *s, int i, int j, char c)
{
	while (s[i] != c && s[i])
	{
		++i;
		++j;
	}
	return (j);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		k;
	int		w;

	if (!s)
		return (0);
	w = wc(s, c);
	ret = (char **)malloc(sizeof(char *) * w + 1);
	if (!ret)
		return (NULL);
	i = 0;
	k = 0;
	ret[w] = 0;
	while (k < w)
	{
		while (s[i] == c)
			++i;
		ret[k] = ft_strsub(s, i, wl(s, i, 0, c));
		while (s[i] && s[i] != c)
			i++;
		++k;
	}
	return (ret);
}
