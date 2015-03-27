#include "push_swap.h"

void		print_move(t_stacks *st, char *str, char *color)
{
	if (st->nb_act && !(st->options & 8))
	{
		ft_putchar(' ');
	}
	if (st->options & 2)
		ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[37m");
	if (st->options & 8)
	{
		ft_putchar('\n');
		print_stacks(st);
	}
}
