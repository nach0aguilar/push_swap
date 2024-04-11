/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:28 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 18:12:23 by igaguila         ###   ########.fr       */
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
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf("pb\n");
}
