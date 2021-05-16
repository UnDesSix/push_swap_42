/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:14:16 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/16 13:12:11 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_correct_pos(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	tmp;
	int	i_max;

	i = 0;
	i_max = stack_b->cur_size - 1;
	tmp = stack_a->tab[0];
//	printf("tmp = %d\n", tmp);
//	printf("stack = %d\n", stack_b->tab[i]);
//	printf("i   = %d\n", i);
	while (tmp < stack_b->tab[i])
		i++;
	if (i == 0)
		;
	else if (i == 1)
		ft_rb(stack_b);
	else if (i <= stack_b->cur_size / 2)
	{
		while (tmp > stack_b->tab[0])
			ft_rb(stack_b);
	}
	else if (i > stack_b->cur_size / 2)
	{
		while (tmp > stack_b->tab[i_max])
			ft_rrb(stack_b);
	}
	ft_pb(stack_a, stack_b);	
	return (0);
}

int		pos_curr_chunk_val(t_stack *stack_a, t_chunk chunk)
{
	int	i;

	i = 0;
//	printf("value : %d\n", stack_a->tab[i]);
//	printf("chunk.min_val : %d\n", chunk.min_val);
//	printf("chunk.max_val : %d\n", chunk.max_val);
	while (chunk.min_val > stack_a->tab[i] && chunk.max_val < stack_a->tab[i])
		i++;
//	printf("i : %d\n\n", i);
	if (i == 0)
		;
	else if (i == 1)
		ft_sa(stack_a);
	else if (i <= stack_a->cur_size / 2)
		while (stack_a->tab[0] != stack_a->tab[i])
			ft_ra(stack_a);
	else
		while (stack_a->tab[0] != stack_a->tab[i])
			ft_rra(stack_a);
	return (0);
}


int		push_b_rev_order(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int i;

	i = 0;
	while (i < chunk.size)
	{
		pos_curr_chunk_val(stack_a, chunk);
		if (stack_b->cur_size < 1)
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

	chunks = create_chunks(stack_init, 20);
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
