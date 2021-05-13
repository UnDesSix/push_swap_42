/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:38:19 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/13 08:00:21 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_atoi_spe(const char *str, int *result)
{
	int		i;
	int		sign;
	long	tmp_result;

	i = 0;
	sign = 1;
	tmp_result = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		tmp_result = tmp_result * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (-2);
	tmp_result *= sign;
	if (tmp_result > 2147483647 || tmp_result < -2147483648)
		return (-3);
	*result = (int)tmp_result;
	return (0);
}
