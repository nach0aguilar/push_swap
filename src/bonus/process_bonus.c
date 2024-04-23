/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:23:04 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/23 16:30:03 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	bonus_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

char	*bonus_process(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		bonus_swap_a(a);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		bonus_rotate_a(a);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		bonus_reverse_a(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		bonus_swap_b(b);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		bonus_rotate_b(b);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		bonus_reverse_b(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		bonus_swap_ab(a, b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		bonus_rotate_ab(a, b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		bonus_reverse_ab(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		bonus_push_a(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		bonus_push_b(a, b);
	else
		bonus_error();
	return (get_next_line(0));
}
