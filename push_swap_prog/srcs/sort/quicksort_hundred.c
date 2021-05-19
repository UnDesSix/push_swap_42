/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 07:04:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/19 16:00:37 by mlarboul         ###   ########.fr       */
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
//		print_stacks(*stack_a, *stack_b);
		top = get_value_pos_top(chunk.min_val, chunk.max_val, stack_a);
		bot = get_value_pos_bot(chunk.min_val, chunk.max_val, stack_a);
//		printf("min :%d\n", chunk.min_val);
//		printf("max :%d\n", chunk.max_val);
//		printf("top :%d\n", top);
//		printf("bot :%d\n", bot);
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
	int	tmp_min;
	int	tmp_max;
	int	status;

	while (stack_b->cur_size > 0)
	{
		status = 1;
//		print_stacks(*stack_a, *stack_b);
		get_min_max_med(stack_b);
		tmp_min = stack_b->info.min;
		tmp_max = stack_b->info.max;
		top = get_value2_pos_top(tmp_min, tmp_max, stack_b);
		bot = get_value2_pos_bot(tmp_min, tmp_max, stack_b);
//		printf("min :%d\n", tmp_min);
//		printf("max :%d\n", tmp_max);
//		printf("top :%d\n", top);
//		printf("bot :%d\n", bot);
//		printf("STA :%d\n", status);
		if (top <= bot)
		{
			if (stack_b->tab[top] == tmp_min)
				status = 0;
			while (top-- > 0)
				ft_rb(stack_b);
		}
		else
		{
			if (stack_b->tab[stack_b->cur_size - 1 - bot] == tmp_min)
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

int	free_top_of_stack(t_stack *stack_a, t_chunk chunk)
{
	while (stack_a->tab[0] > chunk.min_val && stack_a->tab[0] <= chunk.max_val)
		ft_ra(stack_a);
	return (0);
}

int	qs_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init)
{
	t_chunk	*chunks;
	int		i;

	chunks = create_chunks(stack_init, 3);
	if (chunks == NULL)
		return (-1);
	i = 0;
	while (i < chunks[0].number)
	{
		find_and_pb_med(stack_a, stack_b, chunks[i].med_val);
		print_stacks(*stack_a, *stack_b);
		if (i > 0)
			while(stack_a->tab[0] != chunks[i - 1].min_val )
				ft_ra(stack_a);
		push_back_on_a(stack_a, stack_b);
		pb_before_and_after_med(stack_a, stack_b, chunks[i]);
		print_stacks(*stack_a, *stack_b);
		if (i > 0)
			while(stack_a->tab[0] >= chunks[i - 1].min_val
					&& stack_a->tab[0] <= chunks[i - 1].max_val )
				ft_ra(stack_a);
		push_back_on_a(stack_a, stack_b);
		print_stacks(*stack_a, *stack_b);
		free_top_of_stack(stack_a, chunks[i]);
		i++;
	}
	print_stacks(*stack_a, *stack_b);
	if (chunks != NULL)
		free(chunks);
	return (0);
}
