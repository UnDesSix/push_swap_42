/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 07:04:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 07:57:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_and_pb_med(t_stack *stack_a, t_stack *stack_b, int median)
{
	int	i;

	i = 0;
	while (stack_a->tab[i] != median)
		i++;
	if (i <= stack_a->cur_size / 2)
		while (stack_a->tab[0] != median)
			ft_ra(stack_a);
	else
		while (stack_a->tab[0] != median)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	return (0);
}

int	pb_before_and_after_med(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int	top;
	int	bot;

	while (stack_b->cur_size < chunk.size)
	{
		top = get_value_pos_top(chunk.min_val, chunk.max_val, stack_a);
		bot = get_value_pos_bot(chunk.min_val, chunk.max_val, stack_a);
		if (top <= bot)
			while (top-- > 0)
				ft_ra(stack_a);
		else
			while (bot-- >= 0)
				ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		if (stack_b->tab[0] > chunk.med_val)
			ft_rb(stack_b);
	}
	return (0);
}

int	push_back_on_a(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	bot;
	int	status;

	while (stack_b->cur_size > 0)
	{
		status = 1;
		get_min_max_med(stack_b);
		top = get_value2_pos_top(stack_b->info.min, stack_b->info.max, stack_b);
		bot = get_value2_pos_bot(stack_b->info.min, stack_b->info.max, stack_b);
		if (top <= bot)
		{
			if (stack_b->tab[top] == stack_b->info.min)
				status = 0;
			while (top-- > 0)
				ft_rb(stack_b);
		}
		else
		{
			if (stack_b->tab[stack_b->cur_size - 1 - bot] == stack_b->info.min)
				status = 0;
			while (bot-- >= 0)
				ft_rrb(stack_b);
		}
		ft_pa(stack_b, stack_a);
		if (status == 0)
			ft_ra(stack_a);
	}
	return (0);
}

int	quick_order_stack_a(t_stack *stack_a, t_chunk *chunks, int i)
{
	int j;

	j = 0;
	if (i > 0)
	{
//		while(stack_a->tab[stack_a->cur_size - 1] != chunks[i - 1].max_val )
//			ft_rra(stack_a);
		while(stack_a->tab[j] != chunks[i - 1].max_val )
			j++;
		if (j <= stack_a->cur_size / 2)
			while (j-- >= 0)
				ft_ra(stack_a);
		else
			while (j++ < stack_a->cur_size - 1)
				ft_rra(stack_a);
	}
	return (0);
}

int	qs_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init, int chunk_size)
{
	t_chunk	*chunks;
	int		i;

	chunks = create_chunks(stack_init, chunk_size);
	if (chunks == NULL)
		return (-1);
	i = 0;
	while (i < chunks[0].number)
	{
		find_and_pb_med(stack_a, stack_b, chunks[i].med_val);
		pb_before_and_after_med(stack_a, stack_b, chunks[i]);
		quick_order_stack_a(stack_a, chunks, i);
			push_back_on_a(stack_a, stack_b);
		while (stack_a->tab[0] > chunks[i].min_val
				&& stack_a->tab[0] <= chunks[i].max_val)
			ft_ra(stack_a);
		i++;
	}
	if (chunks != NULL)
		free(chunks);
	return (0);
}
