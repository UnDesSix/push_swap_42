/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_hundred_part2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:51:41 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 09:55:37 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_back_on_a_part2(t_stack *stack_b, int top, int bot, int *status)
{
	if (top <= bot)
	{
		if (stack_b->tab[top] == stack_b->info.min)
			*status = 0;
		while (top-- > 0)
			ft_rb(stack_b);
	}
	else
	{
		if (stack_b->tab[stack_b->cur_size - 1 - bot] == stack_b->info.min)
			*status = 0;
		while (bot-- >= 0)
			ft_rrb(stack_b);
	}
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
		push_back_on_a_part2(stack_b, top, bot, &status);
		ft_pa(stack_b, stack_a);
		if (status == 0)
			ft_ra(stack_a);
	}
	return (0);
}
