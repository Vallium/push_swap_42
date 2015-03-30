/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 18:07:40 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/28 18:07:42 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cmp(void *a, void *b)
{
	int		a1;
	int		b1;

	a1 = *(int *)a;
	b1 = *(int *)b;
	return (a1 > b1);
}

void	check_dups(t_stacks st)
{
	int		size;
	int		*data;
	int		**ptr;
	int		i;

	data = lst2tab(&st.sa, &size);
	ptr = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		ptr[i] = &data[i];
		i++;
	}
	ft_sort_qck((void **)ptr, size, cmp);
	i = 1;
	while (i < size)
	{
		if (*ptr[i - 1] == *ptr[i])
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		i++;
	}
}

int		ft_atoi_err(const char *str, int *err)
{
	unsigned int	ret;
	unsigned int	prev;
	char			si;

	ret = 0;
	si = 1;
	*err = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		si = (*str++ == '-' ? -1 : 1);
	while (ft_isdigit(*str))
	{
		prev = ret;
		ret = ret * 10 + (*str - '0');
		if (prev > ret)
			*err = 1;
		str++;
	}
	if ((ret - 1 > INT_MAX && si < 0) || (ret > INT_MAX && si > 0))
		*err = 1;
	return (si * ret);
}

int		error_handling(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-')
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
