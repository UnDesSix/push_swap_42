/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:43:23 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 09:45:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_bool	at_the_end(t_stack *stack, int min, int max)
{
	if (stack->tab[stack->cur_size - 1] == min
		|| stack->tab[stack->cur_size - 1] == max)
		return (TRUE);
	return (FALSE);
}

int	pb_min_max(t_stack *stack_a, t_stack *stack_b)
{
	if (at_the_end(stack_a, stack_a->info.min, stack_a->info.max) == TRUE)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	if (at_the_end(stack_a, stack_a->info.min, stack_a->info.max) == TRUE)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->cur_size < 2)
	{
		if (stack_a->tab[0] == stack_a->info.min
			|| stack_a->tab[0] == stack_a->info.max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	return (0);
}

int	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	get_min_max_med(stack_a);
	pb_min_max(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->cur_size > 0)
	{
		ft_pa(stack_b, stack_a);
		if (stack_a->tab[0] > stack_a->tab[1])
			ft_ra(stack_a);
	}
	return (0);
}
