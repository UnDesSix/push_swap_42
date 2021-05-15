/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:01:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 08:36:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_rra(t_stack *stack)
{
	int	i;
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	i = stack->cur_size - 1;
	tmp_value = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp_value;
	write(1, "rra\n", 4);
	return (0);
}

int		ft_rrb(t_stack *stack)
{
	int	i;
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	i = stack->cur_size - 1;
	tmp_value = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp_value;
	write(1, "rrb\n", 4);
	return (0);
}

int		ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_rra(stack_a) < 0)
		return (-1);
	if (ft_rrb(stack_b) < 0)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
