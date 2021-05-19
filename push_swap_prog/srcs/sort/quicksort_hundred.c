/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 07:04:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/19 13:43:27 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



int	find_and_pb_med(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	i;

	i = 0;
	while (stack_a.tab[i] != median)
		i++;
	if (i <= stack_a.cur_size / 2)
		while (stack_a.tab[0] != median)
			ft_ra(stack_a);
	else
		while (stack_a.tab[0] != median)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	return (0);
}

int	pb_before_and_after_med(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int	top;
	int	bot;

	while (stack_b.size < chunk.size)
	{
		top = get_value_pos_top(chunk.min_val, chunk.max_val, stack_a);
		bot = get_value_pos_bot(chunk.min_val, chunk.max_val, stack_a);
		if (top >= bot)
			while (top-- > 0)
				ft_ra(stack_a);
		else
			while (bot-- >= 0)
				ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		if (stack_b.tab[0] > chunk.med_val)
			ft_rb(stack_b);
	}
}

int	push_back_on_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int	top;
	int	bot;
	int	tmp_min;
	int	tmp_max;

	while (stack_b.size > 0)
	{
		get_min_max_med(stack_b);
		tmp_min = stack_b->info.min;
		tmp_max = stack_b->info.max;
		top = get_value2_pos_top(tmp_min, tmp_max, stack_b);
		top = get_value2_pos_top(tmp_min, tmp_max, stack_b);
		if (top >= bot)
			while (top-- > 0)
				ft_rb(stack_a);
		else
			while (bot-- >= 0)
				ft_rrb(stack_a);
		ft_pa(stack_b, stack_a);
		if (stack_a.tab[0] == tmp_min)
			ft_ra(stack_b);
	}
	return (0);
}

int	

int	qs_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init)
{
	t_chunk	chunks;
	int		i;

	chunks = create_chunks(stack_init, 20);
	if (chunks == NULL)
		return (-1);
	i = 0;
	while (i < chunks[0].number)
	{
		find_and_pb_med(stack_a, stack_b, chunk[i].med_val);
		pb_before_and_after_med(stack_a, stack_b, chunk[i]);
		push_back_on_a(stack_a, stack_b, chunk[i]);
		free_top_of_stack(stack_a, chunk[i]);
		i++;
	}
	return (0);
}
