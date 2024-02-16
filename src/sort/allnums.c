/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/16 14:38:00 by igaguila         ###   ########.fr       */
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

void	rotateandreverse(t_stack **a, t_stack **b, int n)
{
	if (n == 1)
	{
		rotate_a(a);
		reverse_b(b);
	}
	else if (n == 2)
	{
		reverse_a(a);
		rotate_b(b);
	}
}

void	sortandpush(t_stack **a, t_stack **b, t_stack *cheapnode)
{
	costcalc(a, b);
	while (cheapnode->cost_a != 0 || cheapnode->cost_b != 0)
	{
		if (cheapnode->cost_a > 0 && cheapnode->cost_b > 0)
			rotate_ab(a, b);
		else if (cheapnode->cost_a < 0 && cheapnode->cost_b < 0)
			reverse_ab(a, b);
		else if (cheapnode->cost_a > 0 && cheapnode->cost_b < 0)
			rotateandreverse(a, b, 1);
		else if (cheapnode->cost_a < 0 && cheapnode->cost_b > 0)
			rotateandreverse(a, b, 2);
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
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack	*cheapnode;

	separation(a, b);
	sort_3(a);
	while (*b != NULL)
	{
		cheapnode = cheapestcost(b);
		sortandpush(a, b, cheapnode);
	}
	while (minnode(a)->pos != 0)
	{
		if (minnode(a)->pos < maxindex(a) / 2)
			rotate_a(a);
		else
			reverse_a(a);
	}
}
