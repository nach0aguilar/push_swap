/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3nums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:24:11 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 13:28:40 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_3(t_stack **a)
{
	if (maxnum(a) == (*a)->nb)
		rotate_a(a);
	else if ((*a)->next->nb == maxnum(a))
		reverse_a(a);
	if ((*a)->nb > (*a)->next->nb)
		swap_a(a);
}
