/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:56:00 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/20 19:23:47 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


static void move_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while(*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rotate_ab(a, b);
    }
}

static void move_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while(*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        reverse_ab(a, b);
    }
}

static void move_rotate_a(t_stack **a, int *cost_a)
{
    while(*cost_a != 0)
    {
        if(*cost_a > 0)
        {
            (*cost_a)--;
            rotate_a(a);
        }
        else if(*cost_a < 0)
        {
            (*cost_a)++;
            reverse_a(a);
        }
    }
}

static void move_rotate_b(t_stack **b, int *cost_b)
{
    while(*cost_b != 0)
    {
        if(*cost_b > 0)
        {
            (*cost_b)--;
            rotate_b(b);
        }
        else if(*cost_b < 0)
        {
            (*cost_b)++;
            reverse_b(b);
        }
    }
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if(cost_a > 0 && cost_b > 0)
        move_rr(a, b, &cost_a, &cost_b);
    else if(cost_a < 0 && cost_b < 0)
        move_rrr(a, b, &cost_a, &cost_b);
    move_rotate_a(a, &cost_a);
    move_rotate_b(b, &cost_b);
	push_a(a, b);
}
