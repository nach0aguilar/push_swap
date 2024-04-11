/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/11 18:04:06 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// void	printstack(t_stack **a, t_stack **b)
// {
// 	t_stack	*cur_a;
// 	t_stack	*cur_b;

// 	cur_a = *a;
// 	cur_b = *b;
// 	printf("\nSTACK A\n");
// 	while (cur_a != NULL)
// 	{
// 		ft_printf("Num: %d - Index: %d - Pos: %d\n", cur_a->nb, cur_a->index,
// 			cur_a->pos);
// 		cur_a = cur_a->next;
// 	}
// 	printf("\n------------------\n");
// 	printf("\nSTACK B\n");
// 	while (cur_b != NULL)
// 	{
// 		ft_printf("Num: %d - Index: %d - Pos: %d\n", cur_b->nb, cur_b->index,
// 			cur_b->pos);
// 		cur_b = cur_b->next;
// 	}
// }

static void	check_space_before_num(char **nums)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (nums[i])
	{
		while(nums[i][j])
		{
			if ((nums[i][j] == '-' || nums[i][j] == '+') && (nums[i][j - 1] >= '0'
					&& nums[i][j - 1] <= '9'))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 1;
		i++;
	}
}

static void	push_swap(t_stack **a, t_stack **b)
{
	if (!checksort(a, b))
	{
		if (stacksize(a) == 2)
			swap_a(a);
		else if (stacksize(a) == 3)
			sort_3(a);
		else
			sort_all(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	long	n;

	if (argc < 2 || checknums(argv) == 0 || strncmp(argv[1], "", 1) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc >= 2)
	{
		check_space_before_num(argv);
		n = ft_atol(ft_split(argv[1], ' ')[1]);
		if (n < -2147483648 || n > 2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = newstack(stack_a, argv);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!checkdup(stack_a))
		return (0);
	push_swap(stack_a, stack_b);
	freestack(stack_a);
	freestack(stack_b);
}
