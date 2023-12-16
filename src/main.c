//#include "../includes/pushswap.h"
#include <stdio.h>
#include <unistd.h>

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
			if (!(nums[i][j] >= '0' && nums[i][j] <= '9')
				&& nums[i][j] != '+' && nums[i][j] != '-' && nums[i][j] != ' ')
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

// static t_stack	*newstack(char **nums)
// {
// }

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	printf("%d\n", checknums(argv));
}