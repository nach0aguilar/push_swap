#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct      s_stack
{
    int             nb;
    struct s_stack  *next;
}                   t_stack;



#endif