/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 12:01:20 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/19 12:02:42 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int		is_sort(t_stacks *stacks)
{
	t_list	*tmp;
	int		i;
	if (stacks->nb_sb > 0)
		return (0);
	if (stacks->nb_sa > 1)
	{
		tmp = stacks->sa;
		i = *(int *)tmp->content;
		tmp = tmp->next;
		while (tmp)
		{
			if (i > *(int *)tmp->content)
				return (0);
			i = *(int *)tmp->content;
			tmp = tmp->next;
		}
	}
	return (1);
}

int		is_presk_sort(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*bfr;

	if (stacks->nb_sa > 3 && stacks->nb_sb == 0)
	{

		tmp = stacks->sa;
		bfr = tmp;
		while (tmp->next)
		{
			bfr = tmp;
			tmp = tmp->next;
		}
		tmp->next = bfr;
		bfr->next = 0;
		if (is_sort(stacks))
		{
			bfr->next = tmp;
			tmp->next = 0;
			return (1);
		}
		bfr->next = tmp;
		tmp->next = 0;
	}
	return (0);
}

int	sa_min(t_stacks *stacks, int *ret)
{
	int i = INT_MAX;
	int index = 0;
	*ret = -1;
	t_list *tmp = stacks->sa;
	while (tmp)
	{
		if (*((int *)tmp->content) < i)
		{
			i = *(int *)tmp->content;
			*ret = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (i);
}

void	free_stacks(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->sa;
	while (tmp->next)
	{
		tmp->content = NULL;
		free(tmp->content);
		tmp = tmp->next;
	}
	stacks->sa = NULL;
	free(stacks->sa);
	tmp = stacks->sb;
	while (tmp->next)
	{
		tmp->content = NULL;
		free(tmp->content);
		tmp = tmp->next;
	}
	stacks->sb = NULL;
	free(stacks->sb);
}

int			ft_atoi_err(const char *str, int *err)
{
	unsigned int		ret;
	unsigned int		prev;
	char	si;

	ret = 0;
	si = 1;
	*err = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		si = (*str == '-' ? -1 : 1);
		str++;
	}
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
			ft_putstr("Error\n");
			return (0);
		}
		while (argv[i][j])
		{
			if(!ft_isdigit(argv[i][j]))
			{
				ft_putstr("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int cmp(void *a, void *b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;
	return (a1 > b1);
}

int		main(int argc, char **argv)
{
	int		nb;
	int		err;
	t_stacks	all;

	all.sa = NULL;
	all.sb = NULL;
	all.nb_sa = 0;
	all.nb_sb = 0;
	all.nb_act = 0;
	if(!error_handling(argv))
		return (0);
	while (all.nb_sa + 1 < argc)
	{
		nb = ft_atoi_err(argv[(all.nb_sa++) + 1], &err);
		if (err)
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_lstsmartpushback(&all.sa, ft_lstnew(&nb, sizeof(int)));
	}

	int size;
	int *data = lst2tab(&all.sa, &size);
	int **ptr = (int **)malloc(sizeof(int *) * size);

	int i;
	for (i=0; i < size; i++)
		ptr[i] = &data[i];

	ft_sort_qck((void **)ptr, size, cmp);


	for (i=1; i < size; i++)
	{
		if (*ptr[i - 1] == *ptr[i])
		{
			ft_putstr("Error\n");
			exit(0);
		}
	}
	if (!is_sort(&all))
		trie(&all);
	ft_putstr("\nNombre de coups = \033[33m");
	ft_putnbr(all.nb_act);
	ft_putstr("\033[37m\n");

	print_stacks(&all);
	return (0);
}
