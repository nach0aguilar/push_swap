/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:08 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/20 21:56:24 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	swap_a(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	ft_printf("sb\n");
}

void	swap_ab(t_stack **a, t_stack **b)
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
	ft_printf("ss\n");
}
