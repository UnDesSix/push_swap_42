/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 08:52:43 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 09:07:12 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_three(t_stack *stack_init, t_stack *stack_a)
{
	if (list_is_sorted(*stack_a))
		return (0);
	else if (stack_a->tab[0] == stack_init->info.med
			&& stack_a->tab[1] == stack_init->info.min)
		ft_sa(stack_a);
	else if (stack_a->tab[0] == stack_init->info.med)
		ft_rra(stack_a);
	else if (stack_a->tab[0] == stack_init->info.max
			&& stack_a->tab[1] == stack_init->info.min)
		ft_ra(stack_a);
	else if (stack_a->tab[0] == stack_init->info.min)
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
