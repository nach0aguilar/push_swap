/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:14:23 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/14 18:41:36 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*maxnode(t_stack **a)
{
	t_stack	*cur;
	t_stack	*maxnode;

	cur = *a;
	maxnode = cur;
	while (cur != NULL)
	{
		if (cur->index > maxnode->index)
			maxnode = cur;
		cur = cur->next;
	}
	return (maxnode);
}

t_stack	*minnode(t_stack **a)
{
	t_stack	*cur;
	t_stack	*minnode;

	cur = *a;
	minnode = cur;
	while (cur != NULL)
	{
		if (cur->index < minnode->index)
			minnode = cur;
		cur = cur->next;
	}
	return (minnode);
}