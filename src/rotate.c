/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:18 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/04 11:32:33 by igaguila         ###   ########.fr       */
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
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
	ft_printf("rr\n");
}
