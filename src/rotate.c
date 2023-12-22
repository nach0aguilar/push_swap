/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:18 by igaguila          #+#    #+#             */
/*   Updated: 2023/12/22 11:37:48 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	rotate_a(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	printf("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	t_stack *temp_a;
	t_stack *temp_b;

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
	printf("rr\n");
}