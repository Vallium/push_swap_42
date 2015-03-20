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

void	do_sa(t_stacks *stacks)
{
	(void)stacks;
}

void	do_rrr(t_stacks *stacks)
{
	do_rra(stacks);
	do_rrb(stacks);
}

void	do_rr(t_stacks *stacks)
{
	do_ra(stacks);
	do_rb(stacks);
}

void	do_ss(t_stacks *stacks)
{
	do_sa(stacks);
	do_sb(stacks);
}

int		main()
{
	ft_putstr("Init Push_swap!\n");
	return (0);
}
