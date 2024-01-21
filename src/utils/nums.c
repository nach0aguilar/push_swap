/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:15:56 by igaguila          #+#    #+#             */
/*   Updated: 2024/01/21 19:50:33 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	checknums(char **nums)
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

int		maxnum(t_stack **a)
{
	t_stack *cur;
	int num;

	cur = *a;
	num = (cur)->nb;
	while(cur != NULL)
	{
		if(cur->nb > num)
			num = cur->nb;
		cur = cur->next;
	}
	return(num);
}