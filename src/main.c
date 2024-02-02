/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/01 17:48:02 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	printstack(t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	while (cur != NULL)
	{
		ft_printf("%d %d\n", cur->nb, cur->index);
		cur = cur->next;
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
	// reverse_a(stack_A);
	// printstack(stack_A);
	// ft_printf("EL STACKSIZE ES: %d\n", stacksize(stack_A));
	// ft_printf("EL NÚMERO MÁXIMO ES: %d", maxnum(stack_A));
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
	// printstack(stack_A);
	free(stack_A);
	free(stack_B);
}
