/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:18 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return ((int)(sign * num));
}

static int	checknums(char **nums)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
			if (!(nums[i][j] >= '0' && nums[i][j] <= '9') && nums[i][j] != '+'
				&& nums[i][j] != '-' && nums[i][j] != ' ')
				return (0);
			else if ((nums[i][j] == '+' || nums[i][j] == '-') && !(nums[i][j
					+ 1] >= '0' && nums[i][j + 1] <= '9'))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

t_stack	*newnode(t_stack *head, int num)
{
	t_stack	*node;
	t_stack	*cur;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = num;
	node->next = NULL;
	if (head == NULL)
		return (node);
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	return (head);
}

t_stack	*newstack(t_stack **stack, char **nums)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (nums[i])
	{
		n = ft_atoi(nums[i++]);
		*stack = newnode(*stack, n);
	}
	return (*stack);
}

void printstack(t_stack **stack)
{
	t_stack *cur;

	cur = *stack;
	while (cur != NULL)
	{
		printf("%d\n", cur->nb);
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
	stack_B = NULL;
}
