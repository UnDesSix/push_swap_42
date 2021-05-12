/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 07:21:42 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 08:11:24 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
**	This function only check if the list is properly sorted.
*/

t_bool	list_is_sorted(int *list, int list_size)
{
	int	i;

	i = 0;
	while (i < list_size - 1)
	{
		if (list[i] >= list[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
