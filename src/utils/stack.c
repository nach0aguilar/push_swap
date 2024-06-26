/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:06:34 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/22 19:05:04 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*addnodes(t_stack *head, int num)
{
	t_stack	*node;
	t_stack	*cur;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = num;
	node->index = 1;
	node->pos = 0;
	node->next = NULL;
	if (head == NULL)
		return (node);
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	return (head);
}

t_stack	*newstack(t_stack **stack, char **nums)
{
	int		i;
	long	n;

	i = -1;
	n = 0;
	while (nums[++i])
	{
		n = ft_atol(nums[i]);
		ft_atol_ps(nums[i]);
		if (n < -2147483648 || n > 2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			freestack(stack);
			exit(EXIT_FAILURE);
		}
		*stack = addnodes(*stack, n);
	}
	addindex(stack);
	position(stack);
	return (*stack);
}

int	stacksize(t_stack **a)
{
	t_stack	*cur;
	int		size;

	cur = *a;
	size = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		size++;
	}
	return (size);
}

int	checksort(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;

	cur_a = *a;
	if (!*b)
	{
		while (cur_a->next != NULL)
		{
			if (cur_a->nb < cur_a->next->nb || cur_a->next == NULL)
				cur_a = cur_a->next;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
