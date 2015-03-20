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

typedef struct	s_stacks
{
	t_list		*sa;
	t_list		*bl_sa;		//before last
	t_list		*l_sa;		//last
	size_t		nb_sa;		//nb d'elements

	t_list		*sb;
	t_list		*bl_sb;		//before last
	t_list		*l_sb;		//last
	size_t		nb_sb;		//nb d'elements

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
