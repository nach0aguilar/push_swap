/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:28 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/06 23:16:01 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	position(a);
	position(b);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	position(a);
	position(b);
	ft_printf("pb\n");
}
