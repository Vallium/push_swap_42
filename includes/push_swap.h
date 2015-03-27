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
# include <limits.h>
# include <stdlib.h>

typedef struct	s_opt
{
	int			nb;
	char		err;
	char		*optstr;
}				t_opt;

typedef struct	s_stacks
{
	t_list		*sa;
	int			nb_sa;
	t_list		*sb;
	int			nb_sb;
	int			nb_act;
	int			options;
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

void			trie(t_stacks *stacks);
int				sa_min(t_stacks *stacks, int *ret);
int				is_sort(t_stacks *stacks);
int				is_presk_sort(t_stacks *stacks);
int				*lst2tab(t_list **lst, int *size);

void			print_stacks(t_stacks *st);
void			print_move(t_stacks *st, char *str, char *color);

int				ft_get_opt(int argc, char *av[], t_opt *opt);

#endif
