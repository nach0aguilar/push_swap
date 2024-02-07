/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/07 15:57:34 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	separation(t_stack **a, t_stack **b)
{
	while (stacksize(a) > (maxindex(a) / 2) && stacksize(a) > 3)
	{
		if ((*a)->index <= (maxindex(a) / 2))
			push_b(a, b);
		else
			rotate_a(a);
	}
	while (stacksize(a) > 3)
	{
		if ((*a)->index <= maxindex(a) - 3)
			push_b(a, b);
		else if ((*a)->index > maxindex(a) - 3)
			rotate_a(a);
	}
}

void	sortandpush(t_stack **a, t_stack **b)
{
	
	while(checksort(a, b) != 1)
	{
		while((*b)->next != NULL)
		{
			if((*b)->index != (*a)->index - 1)
			{
				rotate_b(b);
			}
			else
				push_a(a, b);
		}
		push_a(a, b);
	}
	
}

void	sort_all(t_stack **a, t_stack **b)
{
	separation(a, b);
	sort_3(a);
	sortandpush(a, b);
}
