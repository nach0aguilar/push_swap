/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:18 by igaguila          #+#    #+#             */
/*   Updated: 2023/12/20 17:47:51 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void    rotate_a(t_stack **a)
{
    t_stack *last;
    t_stack *temp;

    last = *a;
    *a = (*a)->next;    
    while((*a)->next != NULL)
    {
        *a = (*a)->next; 
    }
    *a = last;
}