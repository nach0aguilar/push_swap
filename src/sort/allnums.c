/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 13:31:11 by igaguila         ###   ########.fr       */
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

static void	finalsort(t_stack **a, int pos)
{
	int	count;

	count = 0;
	if (pos < maxindex(a) / 2)
	{
		while (pos != 0)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (count != stacksize(a) - pos)
		{
			reverse_a(a);
			count++;
		}
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	int	min_pos;

	separation(a, b);
	sort_3(a);
	while (*b != NULL)
	{
		costcalc(a, b);
		cheapestmove(a, b);
		position(a);
	}
	min_pos = minnode(a)->pos;
	if (!checksort(a, b))
		finalsort(a, min_pos);
}
