/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:14:16 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/17 09:04:55 by mlarboul         ###   ########.fr       */
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
//	i_max = stack_b->cur_size - 1;
	tmp = stack_a->tab[0];
	get_min_max_med(stack_b);
//	printf("tmp = %d\n", tmp);
//	printf("stack = %d\n", stack_b->tab[i]);
//	printf("i   = %d\n", i);
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
//		while (tmp > stack_b->tab[0])
		while (i > 0)
		{
			ft_rb(stack_b);
			i--;
		}
	else if (i > stack_b->cur_size / 2)
//		while (tmp > stack_b->tab[stack_b->cur_size - 1])
		while (i < stack_b->cur_size - 1)
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
//		printf("TMP[%d - %d] = %d\n", j, i, tmp[j - i]);
		i++;
	}
//	printf("chunk.size  : %d\n", chunk.size);
//	printf("chunk.min_v : %d\n", chunk.min_val);
//	printf("chunk.max_v : %d\n", chunk.max_val);
//	printf("i           : %d\n", i);
//	printf("front       : %d\n\n", front);
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
	(void)stack_b;
	i = 0;
	while (i < chunk.size)
	{
		print_stacks(*stack_a, *stack_b);
		printf("chunk.min_v : %d\n", chunk.min_val);
		printf("chunk.max_v : %d\n", chunk.max_val);
		pos_curr_chunk_val(stack_a, chunk);
		if (stack_b->cur_size < 2)
			ft_pb(stack_a, stack_b);
		else
			get_correct_pos(stack_a, stack_b);
		i++;
	}
	return (0);
}

int		sort_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init)
{
	t_chunk	*chunks;
	int		i;

	chunks = create_chunks(stack_init, 40);
	if (chunks == NULL)
		return (-1);
	i = 0;
	while (i < chunks[0].number)
	{
		push_b_rev_order(stack_a, stack_b, chunks[i]);
		i++;
	}
	return (0);
}
