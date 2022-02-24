/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:37:16 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/02/23 19:38:48 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				score_a;
	int				rscore_a;
	int				score_b;
	int				rscore_b;
}					t_stack;

int		check_args(int argc, char **argv);
int		check_if_not_final_sorted(int argc, char **argv);
void	push_swap(int argc, char **argv);
t_stack	*sort(t_stack *a, t_stack *b, int argc);
void	sort_3(t_stack **a);
void	final_sort(t_stack **a);

void	init_scores(t_stack **b);
void	count_score(t_stack *a, t_stack **b);
void	process_score(t_stack **a, t_stack **b);
void	rotate_async(t_stack **a, t_stack **b, char first, t_stack *tmp);

t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int		ft_stacklen(t_stack *a);
t_stack	*ft_stackmin(t_stack *a);
void	ft_free_stack(t_stack *a);

void	p(t_stack **a, t_stack **b, char name);
void	s(t_stack **a, char name);
void	r(t_stack **a, char name);
void	rr(t_stack **a, char name);
void	rab(t_stack **a, t_stack **b);
void	rrab(t_stack **a, t_stack **b);

void	free_mass(int size, char **mas);
void	warning(int code, char *mess);

#endif