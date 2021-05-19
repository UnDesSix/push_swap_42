/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:14:16 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/19 07:52:09 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_correct_pos(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = stack_b->cur_size - 1;
	tmp = stack_a->tab[0];
	get_min_max_med(stack_b);
	if (tmp < stack_b->info.min || tmp > stack_b->info.max)
		while (stack_b->tab[0] != stack_b->info.max)
			ft_rb(stack_b);
	else
	{
		while (!(tmp > stack_b->tab[i] && tmp < stack_b->tab[j]))
		{
			i++;
			j++;
			if (j == stack_b->cur_size)
				j = 0;
		}
	if (i == 0)
		;
	else if (i == 1)
		ft_rb(stack_b);
	else if (i <= stack_b->cur_size / 2)
		while (i > 0)
		{
			ft_rb(stack_b);
			i--;
		}
	else if (i > stack_b->cur_size / 2)
		while (i < stack_b->cur_size)
		{
			ft_rrb(stack_b);
			i++;
		}
	}
	ft_pb(stack_a, stack_b);	
	return (0);
}

int		pos_curr_chunk_val(t_stack *stack_a, t_chunk chunk)
{
	int	i;
	int	j;
	int front;
	int	*tmp;

	i = 0;
	j = stack_a->cur_size - 1;
	tmp = stack_a->tab;
	while (i <= stack_a->cur_size / 2
				&& !(tmp[i] >= chunk.min_val && tmp[i] <= chunk.max_val))
		i++;
	front = i;
	i = 0;
	while (j - i >= stack_a->cur_size / 2 + 1
				&& !(tmp[j - i] >= chunk.min_val && tmp[j - i] <= chunk.max_val))
	{
		i++;
	}
	if (front <= i)
	{
		if (front == 0)
			;
		else if (front == 1)
			ft_sa(stack_a);
		else
			while (front-- > 0)
				ft_ra(stack_a);
	}
	else
		while (i-- >= 0)
			ft_rra(stack_a);
	return (0);
}


int		push_b_rev_order(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int i;
	
	i = 0;
	while (i < chunk.size)
	{
//		print_stacks(*stack_a, *stack_b);
		pos_curr_chunk_val(stack_a, chunk);
		if (stack_b->cur_size < 2)
			ft_pb(stack_a, stack_b);
		else
			get_correct_pos(stack_a, stack_b);
		i++;
	}
	get_min_max_med(stack_b);
	return (0);
}

int		sort_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init)
{
	t_chunk	*chunks;
	int		i;

	chunks = create_chunks(stack_init, 25);
	if (chunks == NULL)
		return (-1);
	i = 0;
	while (i < chunks[0].number)
	{
		push_b_rev_order(stack_a, stack_b, chunks[i]);
		i++;
	}
//	print_stacks(*stack_a, *stack_b);
	i = 0;
	get_min_max_med(stack_b);
	while (stack_b->info.max != stack_b->tab[i])
		i++;
	if (i < stack_b->cur_size / 2)
		while (i-- > 0)
			ft_rb(stack_b);
	else
		while (i++ < stack_b->cur_size)
			ft_rrb(stack_b);
	while (stack_b->cur_size > 0)
		ft_pa(stack_b, stack_a);
	if (chunks != NULL)
		free(chunks);
	return (0);
}
