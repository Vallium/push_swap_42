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

int		sa_min(t_stacks *stacks, int *ret)
{
	t_list	*tmp;
	int		i;
	int		index;

	*ret = -1;
	i = INT_MAX;
	index = 0;
	tmp = stacks->sa;
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

int		cmp(void *a, void *b)
{
	int		a1;
	int		b1;

	a1 = *(int *)a;
	b1 = *(int *)b;
	return (a1 > b1);
}

void	fill_stacks(t_stacks *st, char **argv, int argc)
{
	int		nb;
	int		err;

	st->sa = NULL;
	st->sb = NULL;
	st->nb_sa = 0;
	st->nb_sb = 0;
	st->nb_act = 0;
	while (st->nb_sa + 1 < argc)
	{
		nb = ft_atoi_err(argv[(st->nb_sa++) + 1], &err);
		if (err)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		ft_lstsmartpushback(&st->sa, ft_lstnew(&nb, sizeof(int)));
	}
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
			ft_putstr("Error\n");
			exit(0);
		}
		i++;
	}
}

void	print_acts_nb(int i)
{
	ft_putstr("Number of actions = \033[33m");
	ft_putnbr(i);
	ft_putstr("\033[37m\n");
}

void	illegal_option(t_opt *opt)
{
	ft_putstr_fd("push_swap: illegal option -- ", 2);
	ft_putchar_fd(opt->err, 2);
	ft_putchar_fd('\n', 2);
//	usage();
	exit (2);
}

int		get_opt_assi(int argc, char **argv, t_opt *opt)
{
	char	c;
	int		i;

	i = 0;
	opt->optstr = "ctv";
	opt->nb = 1;
	while ((c = ft_get_opt(argc, argv, opt)) > 0)
	{
		if (c == '?')
			illegal_option(opt);
		i = (c == 'v') ? i | 1 : i;
		i = (c == 'c') ? i | 2 : i;
		i = (c == 't') ? i | 4 : i;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_stacks	all;
	t_opt		opt;

	if (argc > 1)
		all.options = get_opt_assi(argc, argv, &opt);
	if(!error_handling(argv + opt.nb - 1))
		return (0);
	fill_stacks(&all, argv + opt.nb - 1, argc - opt.nb + 1);
	check_dups(all);
	if (!is_sort(&all))
		trie(&all);
	if (all.options & 4)
		print_acts_nb(all.nb_act);
	if (all.options & 1)
		print_stacks(&all);
	return (0);
}
