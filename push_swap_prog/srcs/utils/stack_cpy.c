/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:34:13 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 10:04:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_cpy(t_stack *src, t_stack *dst)
{
	int	i;

	i = 0;
	if (dst == NULL || src->tab == NULL || src->cur_size == 0)
		return (-1);
	dst->tab = malloc(sizeof(int) * src->cur_size);
	if (dst->tab == NULL)
		return (-1);
	while (i < src->cur_size)
	{
		dst->tab[i] = src->tab[i];
		i++;
	}
	dst->cur_size = src->cur_size;
	dst->max_size = src->cur_size;
	return (0);
}
