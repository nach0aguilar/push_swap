/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/15 16:39:45 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	separation(t_stack **a, t_stack **b)
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

void	sortandpush(t_stack **a, t_stack **b, t_stack *cheapnode)
{
	while(cheapnode->cost_a != 0 || cheapnode->cost_b != 0)
	{
		if(cheapnode->cost_a > 0 && cheapnode->cost_b > 0)
			rotate_ab(a, b);
		else if (cheapnode->cost_a < 0 && cheapnode->cost_b < 0)
			reverse_ab(a, b);
		else if (cheapnode->cost_a > 0 && cheapnode->cost_b < 0)
		{
			rotate_a(a);
			reverse_b(b);
		}
		else if (cheapnode->cost_a < 0 && cheapnode->cost_b > 0)
		{
			reverse_a(a);
			rotate_b(b);
		}
		else if (cheapnode->cost_a < 0 && cheapnode->cost_b == 0)
			reverse_a(a);
		else if (cheapnode->cost_a > 0 && cheapnode->cost_b == 0)
			rotate_a(a);
		else if (cheapnode->cost_a == 0 && cheapnode->cost_b < 0)
			reverse_b(b);
		else if (cheapnode->cost_a == 0 && cheapnode->cost_b > 0)
			rotate_b(b);	
		costcalc(a, b);
	}
	push_a(a, b);
	costcalc(a, b);	
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack *cheapnode;
	separation(a, b);
	sort_3(a);
	costcalc(a, b);
	while(*b != NULL)
	{
		cheapnode = cheapestcost(b);
		sortandpush(a, b, cheapnode);
	}
	while(minnode(a)->pos != 0)
	{
		if(minnode(a)->pos < maxindex(a) / 2)
			rotate_a(a);
		else
			reverse_a(a);
	}
}
