/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:15:56 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/23 15:55:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	checknums(char **nums)
{
	int	i;
	int	j;

	i = 0;
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

int	checkdup(t_stack **a)
{
	t_stack	*cur;
	t_stack	*comp;

	cur = *a;
	while (cur != NULL)
	{
		comp = cur->next;
		while (comp != NULL)
		{
			if (comp->nb == cur->nb)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			comp = comp->next;
		}
		cur = cur->next;
	}
	return (1);
}

int	maxnum(t_stack **a)
{
	t_stack	*cur;
	int		num;

	cur = *a;
	num = (cur)->nb;
	while (cur != NULL)
	{
		if (cur->nb > num)
			num = cur->nb;
		cur = cur->next;
	}
	return (num);
}

long	ft_atol_ps(const char *str)
{
	long	i;
	long	sign;
	long	num;

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
	if (str[i])
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
	return ((long)(sign * num));
}
