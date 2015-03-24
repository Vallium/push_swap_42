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

	tmp = stacks->sa;
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
	return (0);
}

void	print_stacks(t_stacks *st)
{
	t_list *tmp;

	tmp = st->sa;
	printf("Pile A (%d elems): ", st->nb_sa);
	while (tmp)
	{
		printf(" %d ->",*((int *)tmp->content));
		tmp = tmp->next;
	}
	printf(" NULL\n");

	tmp = st->sb;
	printf("Pile B (%d elems): ", st->nb_sb);
	while (tmp)
	{
		printf(" %d ->",*((int *)tmp->content));
		tmp = tmp->next;
	}
	printf(" NULL\n");
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

int		error_handling(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
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

int		main(int argc, char **argv)
{
	int nb;
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
		nb = ft_atoi(argv[(all.nb_sa++) + 1]);
		ft_lstsmartpushback(&all.sa, ft_lstnew(&nb, sizeof(int)));
	}
	//print_stacks(&all);

	if (!is_sort(&all))
		trie(&all);

	printf("\nNombre de coups = \033[33m%d\033[37m\n", all.nb_act);

	print_stacks(&all);
	return (0);
}
