/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:25 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 13:25:21 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lastnode;

	temp = NULL;
	lastnode = *stack;
	while (lastnode->next)
	{
		temp = lastnode;
		lastnode = lastnode->next;
	}
	lastnode->next = *stack;
	*stack = lastnode;
	temp->next = NULL;
}

void	bonus_reverse_a(t_stack **a)
{
	bonus_reverse(a);
}

void	bonus_reverse_b(t_stack **b)
{
	bonus_reverse(b);
}

void	bonus_reverse_ab(t_stack **a, t_stack **b)
{
	bonus_reverse(a);
	bonus_reverse(b);
}
