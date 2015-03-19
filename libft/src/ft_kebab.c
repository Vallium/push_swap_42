/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kebab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 21:45:47 by aalliot           #+#    #+#             */
/*   Updated: 2015/01/15 21:45:47 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void		ft_kebab(char *buff, const char *first, ...)
{
	int			i;
	int			j;
	const char	*next;
	va_list		lst;

	va_start(lst, first);
	next = first;
	i = 0;
	while (next != NULL)
	{
		j = 0;
		while (next[j] != 0)
		{
			buff[i] = next[j];
			i++;
			j++;
		}
		next = va_arg(lst, char*);
	}
	va_end(lst);
	buff[i] = 0;
}
