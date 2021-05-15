/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:01:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 11:28:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_ra(t_stack *stack)
{
	int	i;
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	i = 0;
	tmp_value = stack->tab[i];
	while (i < stack->cur_size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp_value;
	write(1, "ra\n", 3);
	ope_nb++;
	return (0);
}

int		ft_rb(t_stack *stack)
{
	int	i;
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	i = 0;
	tmp_value = stack->tab[i];
	while (i < stack->cur_size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp_value;
	write(1, "rb\n", 3);
	ope_nb++;
	return (0);
}

int		ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_ra(stack_a) < 0)
		return (-1);
	if (ft_rb(stack_b) < 0)
		return (-1);
	write(1, "rr\n", 3);
	ope_nb++;
	return (0);
}
