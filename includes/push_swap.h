/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 12:02:53 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/19 12:03:49 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_stacks
{
	t_list		*sa;
	int			nb_sa;
	t_list		*sb;
	int			nb_sb;
}				t_stacks;

void			do_sa(t_stacks *stacks);
void			do_sb(t_stacks *stacks);
void			do_pa(t_stacks *stacks);
void			do_pb(t_stacks *stacks);
void			do_ra(t_stacks *stacks);
void			do_rb(t_stacks *stacks);
void			do_rra(t_stacks *stacks);
void			do_rrb(t_stacks *stacks);
void			do_ss(t_stacks *stacks);
void			do_rr(t_stacks *stacks);
void			do_rrr(t_stacks *stacks);

#endif
