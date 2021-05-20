/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_med.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 07:04:14 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 10:39:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(int *value1, int *value2)
{
	int	tmp_value;

	tmp_value = *value1;
	*value1 = *value2;
	*value2 = tmp_value;
}

int	bubble_sort(t_stack *stack)
{
	int		i;
	int		j;
	t_stack	tmp_stack;

	tmp_stack = *stack;
	i = -1;
	while (++i < tmp_stack.max_size)
	{
		j = i;
		while (++j < tmp_stack.max_size)
			if (tmp_stack.tab[i] > tmp_stack.tab[j])
				ft_swap(&(tmp_stack.tab[i]), &(tmp_stack.tab[j]));
	}
	return (0);
}

int	get_min_max_med(t_stack *stack)
{
	t_stack	tmp_stack;
	int		i;
	int		j;

	if (stack_cpy(stack, &tmp_stack) < 0)
		return (-1);
	i = -1;
	while (++i < tmp_stack.max_size)
	{
		j = i;
		while (++j < tmp_stack.max_size)
			if (tmp_stack.tab[i] > tmp_stack.tab[j])
				ft_swap(&(tmp_stack.tab[i]), &(tmp_stack.tab[j]));
	}
	stack->info.min = tmp_stack.tab[0];
	stack->info.max = tmp_stack.tab[tmp_stack.max_size - 1];
	stack->info.med = tmp_stack.tab[(tmp_stack.max_size) / 2];
	if (tmp_stack.tab != NULL)
		free(tmp_stack.tab);
	return (0);
}
