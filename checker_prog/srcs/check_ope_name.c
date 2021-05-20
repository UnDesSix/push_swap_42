/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ope_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 06:59:03 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 09:36:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
**	This function only check if the operation name is correct.
*/

t_bool	operation_is_valid(char *ope)
{
	if (ft_strlen(ope) == 2 && (!ft_strncmp(ope, "sa", 2)
			|| !ft_strncmp(ope, "sb", 2)
			|| !ft_strncmp(ope, "ss", 2)
			|| !ft_strncmp(ope, "pa", 2)
			|| !ft_strncmp(ope, "pb", 2)
			|| !ft_strncmp(ope, "ra", 2)
			|| !ft_strncmp(ope, "rb", 2)
			|| !ft_strncmp(ope, "rr", 2)))
		return (TRUE);
	else if (ft_strlen(ope) == 3 && (!ft_strncmp(ope, "rra", 3)
			|| !ft_strncmp(ope, "rrb", 3)
			|| !ft_strncmp(ope, "rrr", 3)))
		return (TRUE);
	return (FALSE);
}
