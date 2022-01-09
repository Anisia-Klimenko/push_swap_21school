/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:06:34 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/01/07 15:05:02 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p(t_stack **a, t_stack **b, char name)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	r(t_stack **a, char name)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_stacklast(*b)->next = tmp;
	write(1, "rr\n", 3);
}

void	rr(t_stack **a, char name)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	write(1, "rr", 2);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rrab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	tmp = (*b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*b);
	(*b) = tmp->next;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}
