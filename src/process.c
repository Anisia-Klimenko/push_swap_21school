/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:54:49 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/01/07 12:02:32 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack **a)
{
	if ((*a)->value < (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		return ;
	if ((*a)->next->value < (*a)->next->next->value
		&& (*a)->next->next->value < (*a)->value)
		return ;
	if ((*a)->next->next->value < (*a)->value
		&& (*a)->value < (*a)->next->value)
		return ;
	s(a, 'a');
}

void	init_scores(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b);
	while (tmp)
	{
		tmp->rscore_a = 0;
		tmp->rscore_b = 0;
		tmp->score_a = 0;
		tmp->score_b = 0;
		tmp = tmp->next;
	}
}

void	count_a_score(t_stack *a, t_stack **b, int len, int last)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpb = (*b);
	while (tmpb)
	{
		tmpa = a;
		if (tmpb->value < last)
		{
			while (tmpa->value < tmpa->next->value && tmpa->value > last)
			{
				tmpa = tmpa->next;
				tmpb->score_a++;
			}
			tmpa = tmpa->next;
			tmpb->score_a++;
		}
		while (tmpb->value > tmpa->value)
		{
			tmpa = tmpa->next;
			tmpb->score_a++;
		}
		tmpb->rscore_a = len - tmpb->score_a;
		tmpb = tmpb->next;
	}
}

void	count_b_score(t_stack **b)
{
	int		count;
	int		len;
	t_stack	*tmp;

	count = 0;
	tmp = (*b);
	len = ft_stacklen(*b);
	while (tmp)
	{
		tmp->score_b = count;
		tmp->rscore_b = len - count;
		count++;
		tmp = tmp->next;
	}
}

void	count_score(t_stack *a, t_stack **b)
{
	t_stack	*tmp;
	int		len;

	tmp = (*b);
	len = ft_stacklen(a);
	count_a_score(a, b, len, ft_stacklast(a)->value);
	count_b_score(b);
	while (tmp)
	{
		tmp = tmp->next;
	}
}
