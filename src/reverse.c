/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:25 by igaguila          #+#    #+#             */
/*   Updated: 2023/12/22 12:35:40 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	reverse_a(t_stack **a)
{
	t_stack	*temp;
    t_stack *first;

    first = *a;
    while ((*a)->next)
		*a = (*a)->next;
	temp = *a;
	first->prev = temp;
    temp->next = first;
	first->next = NULL;
	printf("ra\n");
}