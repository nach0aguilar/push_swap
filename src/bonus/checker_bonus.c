/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:58:35 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/22 19:21:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	bonus_checker(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		bonus_swap_a(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		bonus_swap_b(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		bonus_swap_ab(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		bonus_rotate_a(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		bonus_rotate_b(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		bonus_rotate_ab(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		bonus_reverse_a(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		bonus_reverse_b(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		bonus_reverse_ab(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		bonus_push_a(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		bonus_push_b(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

// static void check_operations(char *op, t_stack **a, t_stack **b)
// {
// 	while (op != NULL)
// 	{
// 		if (strncmp(op, "Error\n", 6) == 0)
// 			exit(EXIT_FAILURE);
// 		bonus_checker(a, b, op);
// 		op = get_next_line(0);
// 	}
// }

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

void	check_input(int argc, char **argv, char **nums)
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
	while (op != NULL)
	{
		if (strncmp(op, "Error\n", 6) == 0)
			return (0);
		bonus_checker(stack_a, stack_b, op);
		free(op);
		op = get_next_line(0);
	}
	free(op);
	if (checksort(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (argc == 2)
		freesplit(nums);
	return (freestack(stack_a),	free(stack_b), 0);
}
