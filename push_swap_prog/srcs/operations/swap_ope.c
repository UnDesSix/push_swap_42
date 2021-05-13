/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:00:39 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/13 12:55:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	single_swap(t_stack *stack)
{
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	tmp_value = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp_value;
	return (0);
}

int	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (single_swap(stack_a) < 0)
		return (-1);
	if (single_swap(stack_b) < 0)
		return (-1);
	return (0);
}
