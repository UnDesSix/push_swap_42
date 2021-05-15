/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_med.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 07:04:14 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 08:41:12 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	bubble_sort(t_stack *stack_init)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	while (i < stack_init->max_size)
	{
		j = i + 1;
		while (j < stack_init->max_size)
		{
			if (stack_init->tab[i] > stack_init->tab[j])
			{
				tmp = stack_init->tab[i];
				stack_init->tab[i] = stack_init->tab[j];
				stack_init->tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_min_max_med(t_stack *stack_init)
{
	bubble_sort(stack_init);
	stack_init->info.min = stack_init->tab[0];
	stack_init->info.max = stack_init->tab[stack_init->max_size - 1];
	stack_init->info.med = stack_init->tab[(stack_init->max_size) / 2];
	return (0);
}
