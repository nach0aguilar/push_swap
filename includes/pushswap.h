/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:54:43 by igaguila          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:25 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// SWAP
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_ab(t_stack **a, t_stack **b);

// PUSH
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);

// ROTATE
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_ab(t_stack **a, t_stack **b);

// REVERSE
void				reverse(t_stack **stack);
void				reverse_a(t_stack **a);
void				reverse_b(t_stack **b);
void				reverse_ab(t_stack **a, t_stack **b);

// INDEX
void				addindex(t_stack **head);
void				position(t_stack **head);
int					pivot(t_stack **s);
int					maxindex(t_stack **a);
int					minindex(t_stack **a);

// STACK
t_stack				*newstack(t_stack **stack, char **nums);
t_stack				*addnodes(t_stack *head, int num);
int					stacksize(t_stack **a);
int					checksort(t_stack **a, t_stack **b);
void				freestack(t_stack **s);

// NUMS
int					checknums(char **nums);
int					maxnum(t_stack **a);
int					checkdup(t_stack **a);

// COSTS
void				addtarget(t_stack **a, t_stack **b);
void				costcalc(t_stack **a, t_stack **b);
t_stack				*cheapestcost(t_stack **b);
int					absvalue(int n);

// NODES
t_stack				*maxnode(t_stack **a);
t_stack				*minnode(t_stack **a);

// SORT
void				sort_3(t_stack **a);
void				sort_all(t_stack **a, t_stack **b);
void				separation(t_stack **a, t_stack **b);
void				sortandpush(t_stack **a, t_stack **b, t_stack *cheapnode);
void				rotateandreverse(t_stack **a, t_stack **b, int n);

#endif