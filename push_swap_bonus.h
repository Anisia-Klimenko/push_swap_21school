/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:41:09 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/02/24 13:19:49 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "srcb/get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// stack
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);

//instructions
void	p(t_stack **a, t_stack **b);
void	r(t_stack **a);
void	rab(t_stack **a, t_stack **b);
void	rr(t_stack **a);
void	rrab(t_stack **a, t_stack **b);
void	s(t_stack **a);
void	ss(t_stack **a, t_stack **b);

// utils
int		check_args(int argc, char **argv);
void	free_mass(int size, char **mas);
void	warning(int code, char *mess);

void	checker(int argc, char **argv);
int		check_sort(t_stack *a, t_stack *b);

#endif