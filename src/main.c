/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/15 16:39:20 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	printstack(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *a;
	cur_b = *b;
	
	printf("\nSTACK A\n");

	while (cur_a != NULL)
	{
		ft_printf("Num: %d - Index: %d - Pos: %d - Tpos: %d\n", cur_a->nb, cur_a->index, cur_a->pos, cur_a->target_pos);
		cur_a = cur_a->next;
	}
	
	printf("\n------------------\n");

	printf("\nSTACK B\n");
	while (cur_b != NULL)
	{
		ft_printf("Num: %d - Index: %d - Pos: %d - Tpos: %d - CostA: %d - CostB: %d\n", cur_b->nb, cur_b->index, cur_b->pos, cur_b->target_pos , cur_b->cost_a, cur_b->cost_b);
		cur_b = cur_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_A;
	t_stack	**stack_B;
	
	if (argc < 2 || checknums(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_A = (t_stack **)malloc(sizeof(t_stack *));
	*stack_A = newstack(stack_A, argv);
	stack_B = (t_stack **)malloc(sizeof(t_stack *));
	
	// if (argc == 4 && checkdup(stack_A) == 1)
	// {
	// 	sort_3(stack_A);
	// 	printf("\n\n");
	// 	printstack(stack_A);
	// }
	// else
	// {
	// 	sort_all(stack_A, stack_B);
	// 	printf("\n\n");
	// 	printstack(stack_A);
	// 	printf("\n\n");
	// 	printstack(stack_B);
	// }

	sort_all(stack_A, stack_B);
	// printf("\n\n");
	// printstack(stack_A, stack_B);
	free(stack_A);
	free(stack_B);
}
