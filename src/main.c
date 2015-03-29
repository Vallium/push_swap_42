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

int		get_opt_assi(int argc, char **argv, t_opt *opt)
{
	char	c;
	int		i;

	i = 0;
	opt->optstr = "ahcv";
	opt->nb = 1;
	while ((c = ft_get_opt(argc, argv, opt)) > 0)
	{
		if (c == '?')
			illegal_option(opt);
		i = (c == 'h') ? i | 1 : i;
		i = (c == 'c') ? i | 2 : i;
		i = (c == 'a') ? i | 4 : i;
		i = (c == 'v') ? i | 8 : i;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_stacks	all;
	t_opt		opt;

	if (argc > 1)
		all.options = get_opt_assi(argc, argv, &opt);
	if (all.options & 1)
	{
		ft_putstr("Push_swap Usage\n");
		return (0);
	}
	if (argc == 1 || !error_handling(argv + opt.nb - 1))
		return (0);
	fill_stacks(&all, argv + opt.nb - 1, argc - opt.nb + 1);
	check_dups(all);
	ft_putstr("\033[37m");
	if (!is_sort(&all))
		trie(&all);
	if (all.options & 4)
	{
		print_acts_nb(all.nb_act, all);
		ft_putstr("Final stacks state:\n");
		print_stacks(&all);
	}
	return (0);
}
