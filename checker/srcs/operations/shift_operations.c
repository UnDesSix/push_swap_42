/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:01:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 14:39:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/*
**	This function will do "ra" or "rb". If one of the arguments is null or
**	that the tab of one the stak is null, it returns -1.
**	Otherwise it operate the rotate and returns 0.
*/

int		single_rotate(t_stack *stack)
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
	return (0);
}

/*
**	This function will do "rra" or "rrb". If one of the arguments is null or
**	that the tab of one the stak is null, it returns -1.
**	Otherwise it operate the rotate and returns 0.
*/

int		single_reverse(t_stack *stack)
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
	return (0);
}

/*
**	This function will do "rr".
*/

int		double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (single_rotate(stack_a) < 0)
		return (-1);
	if (single_rotate(stack_b) < 0)
		return (-1);
	return (0);
}

/*
**	This function will do "rrr".
*/

int		double_reverse(t_stack *stack_a, t_stack *stack_b)
{
	if (single_reverse(stack_a) < 0)
		return (-1);
	if (single_reverse(stack_b) < 0)
		return (-1);
	return (0);
}
