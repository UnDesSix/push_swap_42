/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 08:52:43 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 14:48:00 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_three(t_stack *stack_a)
{
	if (list_is_sorted(*stack_a) == TRUE)
		return (0);
	if (get_min_max_med(stack_a) < 0)
		return (-1);
	if (stack_a->tab[0] == stack_a->info.med
			&& stack_a->tab[1] == stack_a->info.min)
		ft_sa(stack_a);
	else if (stack_a->tab[0] == stack_a->info.med)
		ft_rra(stack_a);
	else if (stack_a->tab[0] == stack_a->info.max
			&& stack_a->tab[1] == stack_a->info.min)
		ft_ra(stack_a);
	else if (stack_a->tab[0] == stack_a->info.min)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	return (0);
}
