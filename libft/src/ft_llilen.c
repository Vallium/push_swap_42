/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llilen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:55:07 by aalliot           #+#    #+#             */
/*   Updated: 2015/01/02 16:55:39 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_llilen(long long int i)
{
	int		ret;

	ret = 1;
	while (i /= 10)
		ret++;
	return (ret);
}
