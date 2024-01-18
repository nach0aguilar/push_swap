/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:33 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/18 13:25:20 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	unsigned int	num;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if ((str[i] == '-') || (str[i] == '+'))
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 		num = num * 10 + (str[i++] - '0');
// 	return ((int)(sign * num));
// }

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

void	addindex(t_stack *head)
{
	t_stack	*cur;
	t_stack	*comp;

	cur = head;
	while (cur != NULL)
	{
		comp = head;
		while (comp != NULL)
		{
			if (cur->nb <= comp->nb)
				comp = comp->next;
			else if (cur->nb > comp->nb)
			{
				cur->index += 1;
				comp = comp->next;
			}
		}
		cur = cur->next;
	}
}

t_stack	*addnodes(t_stack *head, int num)
{
	t_stack	*node;
	t_stack	*cur;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = num;
	node->index = 1;
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
		*stack = addnodes(*stack, n);
	}
	addindex(*stack);
	return (*stack);
}

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

	// t_stack	**stack_B;
	if (argc < 2 || checknums(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_A = (t_stack **)malloc(sizeof(t_stack *));
	*stack_A = newstack(stack_A, argv);
	// stack_B = NULL;
	reverse_a(stack_A);
	printstack(stack_A);
}
// para calcular el indice de cada numero tengo que recorrer la lista
// tantas veces como numeros tenga y sumarle al indice del numero al que se
// lo quiero asignar las veces que sea mayor que el resto de numeros
// una vez tenga todos los indices calculare la media de los mismos para
// decidir el pivote

/*
FUNCIONES QUE NECESITO:
- Longitud del stack.
- Asignador de indices.
- Calculadora de la media de los indices (pivote).
*/