/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:04:41 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/20 15:10:53 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	addindex(t_stack *head)
{
	t_stack	*cur;
	t_stack	*comp;

	cur = head;
	while (cur != NULL)
	{
		comp = head;
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

