/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:08 by igaguila          #+#    #+#             */
/*   Updated: 2023/12/20 14:15:02 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void swap_a(t_stack **stack)
{
    int temp;

    temp = (*stack)->nb;
    (*stack)->nb = (*stack)->next->nb;
    (*stack)->next->nb = temp;

    ft_printf("sa");
}

void swap_a(t_stack **stack)
{
    int temp;

    temp = (*stack)->nb;
    (*stack)->nb = (*stack)->next->nb;
    (*stack)->next->nb = temp;

    ft_printf("sb");
}

void swap_ab(t_stack **a, t_stack **b)
{
    int temp_a;
    int temp_b;

    temp_a = (*a)->nb;
    (*a)->nb = (*a)->next->nb;
    (*a)->next->nb = temp_a;

    temp_b = (*b)->nb;
    (*b)->nb = (*b)->next->nb;
    (*b)->next->nb = temp_b;

    ft_printf("ss");
}