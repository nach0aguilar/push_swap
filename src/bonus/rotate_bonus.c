/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:00:27 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/22 19:11:40 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_rotate_a(t_stack **a)
{
	t_stack	*temp;

	if (stacksize(a) < 2)
		return ;
	temp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
}

void	bonus_rotate_b(t_stack **b)
{
	t_stack	*temp;

	if (stacksize(b) < 2)
		return ;
	temp = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
}

void	bonus_rotate_ab(t_stack **a, t_stack **b)
{
	bonus_rotate_a(a);
	bonus_rotate_b(b);
}
