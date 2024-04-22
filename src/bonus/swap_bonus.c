/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:54 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/22 19:17:40 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_swap_a(t_stack **a)
{
	t_stack	*temp;

	if (stacksize(a) < 2)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	bonus_swap_b(t_stack **b)
{
	t_stack	*temp;

	if (stacksize(b) < 2)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
}

void	bonus_swap_ab(t_stack **a, t_stack **b)
{
	bonus_swap_a(a);
	bonus_swap_b(b);
}
