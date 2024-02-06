/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:25 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/06 23:16:57 by igaguila         ###   ########.fr       */
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
	position(a);
	ft_printf("rra\n");
}
void	reverse_b(t_stack **b)
{
	reverse(b);
	position(b);
	ft_printf("rrb\n");
}

void	reverse_ab(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	position(a);
	position(b);
	ft_printf("rrr\n");
}
