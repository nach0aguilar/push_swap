/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:25 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/20 21:56:00 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	reverse(t_stack **stack)
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

void	reverse_a(t_stack **a)
{
	reverse(a);
	ft_printf("rra\n");
}
void	reverse_b(t_stack **b)
{
	reverse(b);
	ft_printf("rrb\n");
}

void	reverse_ab(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}
