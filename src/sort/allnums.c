/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:50:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/01 10:57:42 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	separation(t_stack **a, t_stack **b)
{
	while (stacksize(a) > 3)
	{
		if ((*a)->index <= maxindex(a) - 3)
			push_b(a, b);
		else if ((*a)->index > maxindex(a) - 3)
			rotate_a(a);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	separation(a, b);
	sort_3(a);
}
