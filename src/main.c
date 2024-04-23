/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/23 15:54:36 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	check_space_before_num(char **nums)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (nums[i])
	{
		while (nums[i][j])
		{
			if ((nums[i][j] == '-' || nums[i][j] == '+') && (nums[i][j
					- 1] >= '0' && nums[i][j - 1] <= '9'))
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

static char	**one_arg_process(char **argv)
{
	long	n;
	char	**nums;

	nums = ft_split(argv[1], ' ');
	n = ft_atol(nums[0]);
	if (n < -2147483648 || n > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		freesplit(nums);
		exit(EXIT_FAILURE);
	}
	return (nums);
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
	char	**nums;

	if (argc < 2)
		return (0);
	else if (strncmp(argv[1], "", 1) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		nums = one_arg_process(argv);
	else
		nums = argv + 1;
	check_space_before_num(argv);
	if (!checknums(nums))
		return (ft_putstr_fd("Error\n", 2), 0);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = newstack(stack_a, nums);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!checkdup(stack_a))
		return (freestack(stack_a), free(stack_b), 0);
	push_swap(stack_a, stack_b);
	if (argc == 2)
		freesplit(nums);
	return (freestack(stack_a), free(stack_b), 0);
}
