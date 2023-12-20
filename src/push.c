/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:28 by igaguila          #+#    #+#             */
/*   Updated: 2023/12/20 13:54:29 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    temp = *b;
    *b = (*b)->next;
	temp->next = *a;
    *a = temp;    
}

void push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    temp = *a;
    *a = (*a)->next;
	temp->next = *b;
    *b = temp;    
}