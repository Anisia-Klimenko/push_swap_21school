/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:56:21 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/02/24 11:42:21 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s(t_stack **a, char name)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rotate_async(t_stack **a, t_stack **b, char first, t_stack *tmp)
{
	int		i;
	int		na;
	int		nb;
	char	second;

	i = 0;
	second = 'a';
	if (first == 'a')
	{
		na = tmp->score_a;
		nb = tmp->rscore_b;
		second = 'b';
	}
	else
	{
		na = tmp->score_b;
		nb = tmp->rscore_a;
	}
	while (i++ < na)
		r(a, first);
	i = 0;
	while (i++ < nb)
		rr(b, second);
}

void	final_sort(t_stack **a)
{
	t_stack	*tmp;

	tmp = ft_stackmin(*a);
	if (ft_stacklen(tmp) * 2 < ft_stacklen(*a))
	{
		while ((*a)->value != tmp->value)
			rr(a, 'a');
	}
	else
	{
		while ((*a)->value != tmp->value)
			r(a, 'a');
	}
}

void	free_mass(int size, char **mas)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mas[i]);
		i++;
	}
}

void	warning(int code, char *mess)
{
	if (code == 1)
		write(2, mess, ft_strlen(mess));
	if (code == 0)
		write(1, mess, ft_strlen(mess));
	exit(code);
}
