/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:46:38 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/02/23 19:39:13 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*list;
	int		i;

	i = 0;
	list = NULL;
	while (i < argc)
	{
		ft_stackadd_back(&list, ft_stacknew(ft_atoi(argv[i])));
		i++;
	}
	return (list);
}

void	find_min(int *min, int *index, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < *min)
		{
			*min = ft_atoi(argv[i]);
			*index = i;
		}
		i++;
	}
}

int	if_int_sorted(int size, int *tmp)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_if_not_sorted(int argc, char **argv)
{
	int		i;
	int		min;
	int		index;
	int		*tmp;

	min = 2147483647;
	find_min(&min, &index, argc, argv);
	i = index;
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		return (0);
	while (i < argc)
	{
		tmp[i - index] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < index + 1)
	{
		tmp[argc - index + i] = ft_atoi(argv[i]);
		i++;
	}
	i = if_int_sorted(argc, tmp);
	free(tmp);
	return (i);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc, argv);
	b = init_stack(0, NULL);
	if (check_if_not_sorted(argc, argv))
		a = sort(a, b, argc);
	final_sort(&a);
	ft_free_stack(a);
}
