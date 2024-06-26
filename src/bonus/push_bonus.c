/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:01 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/22 19:18:07 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	bonus_push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
