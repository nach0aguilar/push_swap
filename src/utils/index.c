/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:04:41 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/07 11:25:14 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	addindex(t_stack **head)
{
	t_stack	*cur;
	t_stack	*comp;

	cur = *head;
	while (cur != NULL)
	{
		comp = *head;
		while (comp != NULL)
		{
			if (cur->nb <= comp->nb)
				comp = comp->next;
			else if (cur->nb > comp->nb)
			{
				cur->index += 1;
				comp = comp->next;
			}
		}
		cur = cur->next;
	}
}

void	position(t_stack **head)
{
	t_stack	*cur;
	int		i;

	cur = *head;
	i = 0;
	while (cur != NULL)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
}

int	pivot(t_stack **s)
{
	int	pivot;

	pivot = (stacksize(s) / 2) + 1;
	return (pivot);
}

int	maxindex(t_stack **a)
{
	t_stack	*cur;
	int		num;

	cur = *a;
	num = (cur)->index;
	while (cur != NULL)
	{
		if (cur->index > num)
			num = cur->index;
		cur = cur->next;
	}
	return (num);
}
