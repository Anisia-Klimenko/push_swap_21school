/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:34:03 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/01/08 13:49:02 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(t_stack *a)
{
	int		min;

	min = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value < min)
			min = a->value;
	}
	return (min);
}

int	max(t_stack *a)
{
	int		max;

	max = a->value;
	while (a->next)
	{
		a = a->next;
		if (a->value > max)
			max = a->value;
	}
	return (max);
}

int	med(t_stack *a)
{
	int		more;
	int		less;
	t_stack	*tmpi;
	t_stack	*tmpj;

	tmpi = a;
	while (tmpi->value != ft_stacklast(a)->value)
	{
		more = 0;
		less = 0;
		tmpj = a;
		while (tmpj->value != ft_stacklast(a)->value)
		{
			if (tmpi->value < tmpj->value)
				more++;
			if (tmpi->value > tmpj->value)
				less++;
			tmpj = tmpj->next;
		}
		if (more == less || more == less + 1)
			return (tmpi->value);
		tmpi = tmpi->next;
	}
	return (0);
}

void	leave_min_max_med(t_stack **a, t_stack **b, int argc)
{
	int		imin;
	int		imax;
	int		imed;
	int		i;

	i = 0;
	imin = min(*a);
	imax = max(*a);
	imed = med(*a);
	if (ft_stacklast(*a)->value != imin && ft_stacklast(*a)->value != imax
		&& ft_stacklast(*a)->value != imed)
	{
		rr(a, 'a');
		p(b, a, 'b');
	}
	while (i++ < argc)
	{
		if (ft_stacklen(*a) == 3)
			return ;
		if ((*a)->value == imin || (*a)->value == imax
			|| (*a)->value == imed)
			r(a, 'a');
		else
			p(b, a, 'b');
	}
}

t_stack	*sort(t_stack *a, t_stack *b, int argc)
{
	if (argc != 3)
		leave_min_max_med(&a, &b, argc);
	sort_3(&a);
	while (b)
	{
		init_scores(&b);
		count_score(a, &b);
		process_score(&a, &b);
	}
	return (a);
}
