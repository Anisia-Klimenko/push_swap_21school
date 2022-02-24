/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisiaklimenko <anisiaklimenko@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:45:38 by anisiaklime       #+#    #+#             */
/*   Updated: 2022/02/24 13:12:54 by anisiaklime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_free_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

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

void	check_cmd(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		s(a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		s(b);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		p(a, b);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		p(b, a);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		r(a);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		r(b);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rab(a, b);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rr(a);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rr(b);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrab(a, b);
	else
		warning(1, "Error\n");
}

void	checker(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc, argv);
	b = init_stack(0, NULL);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_cmd(line, &a, &b);
		free(line);
	}
	if (check_sort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(a);
}
