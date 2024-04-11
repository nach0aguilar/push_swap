/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:54 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 13:24:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_swap_a(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	bonus_swap_b(t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
}

void	bonus_swap_ab(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	*a = (*a)->next;
	temp_a->next = (*a)->next;
	(*a)->next = temp_a;
	temp_b = *b;
	*b = (*b)->next;
	temp_b->next = (*b)->next;
	(*b)->next = temp_b;
}
