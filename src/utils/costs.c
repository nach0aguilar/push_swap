/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:33:26 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/21 09:51:05 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int     absvalue(int n)
{
    if(n < 0)
        return(n * -1);
    else
        return(n);
}

static void	addtarget(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	t_stack	*target;

	cur_a = *a;
	cur_b = *b;
	target = NULL;
    position(a);
	position(b);
	while (cur_b != NULL)
	{
		cur_a = *a;
		target = NULL;
		while (cur_a != NULL)
		{
			if (cur_b->index < cur_a->index && (!target
					|| cur_a->index <= target->index))
				target = cur_a;
			else if (cur_b->index > maxindex(a))
				target = minnode(a);
			cur_a = cur_a->next;
		}
		cur_b->target_pos = target->pos;
		cur_b = cur_b->next;
	}
}

void costcalc(t_stack **a, t_stack **b)
{
    t_stack *cur_b;

    cur_b = *b;
    addtarget(a, b);
    while(cur_b != NULL)
    {
        if(cur_b->target_pos <= stacksize(a) / 2)
            cur_b->cost_a = cur_b->target_pos;
        else
            cur_b->cost_a = (stacksize(a) - cur_b->target_pos) * -1;
        if(cur_b->pos <= stacksize(b) / 2)
            cur_b->cost_b = cur_b->pos;
        else
            cur_b->cost_b = (stacksize(b) - cur_b->pos) * -1;
        cur_b = cur_b->next;
    }
}

void cheapestmove(t_stack **a, t_stack **b)
{
    t_stack *cur_b;
    int     cost_a;
    int     cost_b;
    int     cheapcost;

    cur_b = *b;
    cheapcost = INT_MAX;
    while(cur_b != NULL)
    {
        if(absvalue(cur_b->cost_a) + absvalue(cur_b->cost_b) < absvalue(cheapcost))
        {
            cheapcost = absvalue(cur_b->cost_a) + absvalue(cur_b->cost_b);
            cost_a = cur_b->cost_a;
            cost_b = cur_b->cost_b;
        }
        cur_b = cur_b->next;
    }
    move(a, b, cost_a, cost_b);
}


