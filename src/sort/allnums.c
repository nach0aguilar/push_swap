/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/20 20:19:21 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	separation(t_stack **a, t_stack **b)
{
	while (stacksize(a) > (maxindex(a) / 2) && stacksize(a) > 3)
	{
		if ((*a)->index <= (maxindex(a) / 2) + 1)
			push_b(a, b);
		else
			rotate_a(a);
	}
	while (stacksize(a) > 3)
		push_b(a, b);
}

void		sort_all(t_stack **a, t_stack **b)
{
	separation(a, b);
	sort_3(a);
	while (*b != NULL)
	{
		costcalc(a, b);
		cheapestmove(a, b);
	}
	while (minnode(a)->pos != 0)
	{
		if (minnode(a)->pos < maxindex(a) / 2)
			rotate_a(a);
		else
			reverse_a(a);
	}
}
