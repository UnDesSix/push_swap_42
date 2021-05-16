/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:00:39 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/16 12:53:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sa(t_stack *stack)
{
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	tmp_value = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp_value;
//	write(1, "sa\n", 3);
	printf("sa\n");
	ope_nb++;
	return (0);
}

int	ft_sb(t_stack *stack)
{
	int	tmp_value;

	if (stack == NULL || stack->tab == NULL)
		return (-1);
	if (stack->cur_size == 0 || stack->cur_size == 1)
		return (0);
	tmp_value = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp_value;
//	write(1, "sb\n", 3);
	printf("sb\n");
	ope_nb++;
	return (0);
}

int	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sa(stack_a) < 0)
		return (-1);
	if (ft_sb(stack_b) < 0)
		return (-1);
//	write(1, "ss\n", 3);
	printf("ss\n");
	ope_nb++;
	return (0);
}
