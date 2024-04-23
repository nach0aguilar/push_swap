/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:58:35 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/23 15:54:53 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	check_operations(char *op, t_stack **a, t_stack **b)
{
	while (op != NULL)
	{
		if (strncmp(op, "Error\n", 6) == 0)
			return ;
		free(op);
		op = bonus_process(a, b, op);
	}
	free(op);
	if (checksort(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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

static void	check_input(int argc, char **argv, char **nums)
{
	if (strncmp(argv[1], "", 1) == 0)
	{
		if (argc == 2)
			freesplit(nums);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	check_space_before_num(argv);
	if (!checknums(nums))
	{
		if (argc == 2)
			freesplit(nums);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**nums;
	char	*op;

	if (argc < 2)
		return (0);
	else if (strncmp(argv[1], "", 1) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		nums = one_arg_process(argv);
	else
		nums = argv + 1;
	check_input(argc, argv, nums);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = newstack(stack_a, nums);
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!checkdup(stack_a))
		return (freestack(stack_a), free(stack_b), 0);
	op = get_next_line(0);
	check_operations(op, stack_a, stack_b);
	if (argc == 2)
		freesplit(nums);
	return (freestack(stack_a), free(stack_b), 0);
}
