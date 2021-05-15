/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 07:21:42 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 09:08:53 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
**	This function only check if the list is properly sorted.
*/

t_bool	list_is_sorted(t_stack stack_a)
{
	int	i;

	i = 0;
	if (stack_a.cur_size != stack_a.max_size)
		return (FALSE);
	while (i < stack_a.cur_size - 1)
	{
		if (stack_a.tab[i] >= stack_a.tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
