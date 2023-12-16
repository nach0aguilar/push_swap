//#include "../includes/pushswap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

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

// static t_stack	*newstack(char *num)
// {
// 	t_stack	*stack;

// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->nb = ft_atoi(num);
// 	return (stack);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_A;
	//t_stack	*stack_B;

	if (argc < 2 || checknums(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	int i = 1;
	while(argv[i])
	{
		stack_A->nb = atoi(argv[i]);
		stack_A = stack_A->next;
		i++;
	}
	stack_A = NULL;

	while(stack_A != NULL)
	{
		printf("%d\n", stack_A->nb);
		stack_A = stack_A->next;
	}
}
