/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:00:27 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/09 18:00:29 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_rotate_a(t_stack **a)
{
	t_stack	*temp;

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

	temp = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
}

void	bonus_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = temp_a;
	*a = temp_a->next;
	temp_a->next = NULL;
	temp_b = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = temp_b;
	*b = temp_b->next;
	temp_b->next = NULL;
}