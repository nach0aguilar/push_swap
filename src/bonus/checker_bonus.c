/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:58:35 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 13:23:13 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	bonus_checker(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		bonus_swap_a(a);
	if (ft_strncmp(op, "sb\n", 3) == 0)
		bonus_swap_b(b);
	if (ft_strncmp(op, "ss\n", 3) == 0)
		bonus_swap_ab(a, b);
	if (ft_strncmp(op, "ra\n", 3) == 0)
		bonus_rotate_a(a);
	if (ft_strncmp(op, "rb\n", 3) == 0)
		bonus_rotate_b(b);
	if (ft_strncmp(op, "rr\n", 3) == 0)
		bonus_rotate_ab(a, b);
	if (ft_strncmp(op, "rra\n", 4) == 0)
		bonus_reverse_a(a);
	if (ft_strncmp(op, "rrb\n", 4) == 0)
		bonus_reverse_b(b);
	if (ft_strncmp(op, "rrr\n", 4) == 0)
		bonus_reverse_ab(a, b);
	if (ft_strncmp(op, "pa\n", 3) == 0)
		bonus_push_a(a, b);
	if (ft_strncmp(op, "pb\n", 3) == 0)
		bonus_push_b(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	*op;

	if (argc < 2 || checknums(argv) == 0)
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = newstack(stack_a, argv);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	op = get_next_line(0);
	while (op != NULL)
	{
		if (strncmp(op, "Error\n", 6) == 0)
			return (0);
		bonus_checker(stack_a, stack_b, op);
		op = get_next_line(0);
	}
	if (checksort(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freestack(stack_a);
	freestack(stack_b);
}
