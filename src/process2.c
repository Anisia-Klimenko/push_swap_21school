/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:35:03 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/01/07 16:19:23 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_score(t_stack *el, int min)
{
	if (el->score_a < min && el->score_a >= el->score_b)
		min = el->score_a;
	if (el->rscore_a < min && el->rscore_a >= el->rscore_b)
		min = el->rscore_a;
	if (el->score_b < min && el->score_b >= el->score_a)
		min = el->score_b;
	if (el->rscore_b < min && el->rscore_b >= el->rscore_a)
		min = el->rscore_b;
	if (el->score_a + el->rscore_b < min)
		min = el->score_a + el->rscore_b;
	if (el->rscore_a + el->score_b < min)
		min = el->rscore_a + el->score_b;
	return (min);
}

void	rotate_sync(char direct, int n, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_stacklen(*b) == 1 && direct == 'f' && n)
		r(a, 'a');
	else if (ft_stacklen(*b) == 1 && direct == 'b' && n)
		rr(a, 'a');
	else
	{
		while (i < n)
		{
			if (direct == 'f')
				rab(a, b);
			else
				rrab(a, b);
			i++;
		}
	}
}

void	rotate1(void f(t_stack **a, char name), char name, int n, t_stack **a)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(a, name);
		i++;
	}
}

void	rotate2(t_stack *tmp, int min, t_stack **a, t_stack **b)
{
	if (tmp->score_a == min && tmp->score_a >= tmp->score_b)
	{
		rotate_sync('f', tmp->score_b, a, b);
		rotate1(r, 'a', min - tmp->score_b, a);
	}
	else if (tmp->score_b == min && tmp->score_b >= tmp->score_a)
	{
		rotate_sync('f', tmp->score_a, a, b);
		rotate1(r, 'b', min - tmp->score_a, b);
	}
	else if (tmp->rscore_a == min && tmp->rscore_a >= tmp->rscore_b)
	{
		rotate_sync('b', tmp->rscore_b, a, b);
		rotate1(rr, 'a', min - tmp->rscore_b, a);
	}
	else if (tmp->rscore_b == min && tmp->rscore_b >= tmp->rscore_a)
	{
		rotate_sync('b', tmp->rscore_a, a, b);
		rotate1(rr, 'b', min - tmp->rscore_a, b);
	}
	else if (tmp->score_a + tmp->rscore_b == min)
		rotate_async(a, b, 'a', tmp);
	else if (tmp->score_b + tmp->rscore_a == min)
		rotate_async(b, a, 'b', tmp);
	p(a, b, 'a');
}

void	process_score(t_stack **a, t_stack **b)
{
	int		min;
	int		min_tmp;
	t_stack	*tmp;
	t_stack	*el;

	min = ft_stacklen(*a) + (*b)->score_b + (*b)->rscore_b;
	el = *b;
	while (el)
	{
		min_tmp = min;
		min = min_score(el, min);
		if (min_tmp != min)
			tmp = el;
		el = el->next;
	}
	rotate2(tmp, min, a, b);
}
