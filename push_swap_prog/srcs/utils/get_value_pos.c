/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:17:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/19 13:35:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/push_swap.h"

int	get_value_pos_top(int min, int max, t_stack *stack)
{
	int	i;

	i = 0;
	while (!(stack->tab[i] > min && stack->tab[i] < max))
		i++;
	return (i);
}

int	get_value_pos_bot(int min, int max, t_stack *stack)
{
	int	i;
	int	pos;

	i = 0;
	pos = stack->cur_size - 1;
	while (!(stack->tab[pos - i] > min && stack->tab[pos - i] < max))
		i++;
	return (i);
}

int	get_value2_pos_top(int val1, int val2, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i] != val1 && stack->tab[i] != val2)
		i++;
	return (i);
}

int	get_value2_pos_bot(int val1, int val2, t_stack *stack)
{
	int	i;
	int	pos;

	i = 0;
	pos = stack->cur_size - 1;
	while (stack->tab[pos - i] != val1 && stack->tab[pos - i] != val2)
		i++;
	return (i);
}
