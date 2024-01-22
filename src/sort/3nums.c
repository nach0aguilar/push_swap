/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3nums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:24:11 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/22 12:37:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
si tengo por ejemplo
2
3
1
rra

1
3
2
rra
sa

2
1
3
sa

3
2
1
ra
sa

3
1
2
ra
*/

void	sort_3(t_stack **a)
{
	if (maxnum(a) == (*a)->nb)
		rotate_a(a);
	else if ((*a)->next->nb == maxnum(a))
		reverse_a(a);
	if ((*a)->nb > (*a)->next->nb)
		swap_a(a);
}
