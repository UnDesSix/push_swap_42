/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 08:55:44 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 14:49:07 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
**	This function will do "pa" or "pb". If one of the arguments is null or
**	that the tab of one the stak is null, it returns -1.
**	Otherwise it operate the push and return 0.
*/

int	ft_pa(t_stack *src, t_stack *dst)
{
	int	i;

	if (!src || !dst || !src->tab || !dst->tab)
		return (-1);
	if (src->cur_size == 0)
		return (0);
	if (dst->cur_size > 0)
	{
		i = dst->cur_size - 1;
		while (i >= 0)
		{
			dst->tab[i + 1] = dst->tab[i];
			i--;
		}
	}
	dst->tab[0] = src->tab[0];
	dst->cur_size++;
	src->cur_size--;
	i = -1;
	while (++i < src->cur_size)
		src->tab[i] = src->tab[i + 1];
	write(1, "pa\n", 3);
	ope_nb++;
	return (0);
}

int	ft_pb(t_stack *src, t_stack *dst)
{
	int	i;

	if (!src || !dst || !src->tab || !dst->tab)
		return (-1);
	if (src->cur_size == 0)
		return (0);
	if (dst->cur_size > 0)
	{
		i = dst->cur_size - 1;
		while (i >= 0)
		{
			dst->tab[i + 1] = dst->tab[i];
			i--;
		}
	}
	dst->tab[0] = src->tab[0];
	dst->cur_size++;
	src->cur_size--;
	i = -1;
	while (++i < src->cur_size)
		src->tab[i] = src->tab[i + 1];
	write(1, "pb\n", 3);
	ope_nb++;
	return (0);
}
