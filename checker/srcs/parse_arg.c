/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:43:12 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/07 08:24:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	free_tmp_list(char **tmp_list, int err_code)
{
	int	i;

	i = 0;
	while (tmp_list[i])
		free(tmp_list[i++]);
	free(tmp_list);
	return (err_code);
}

/*
**	This function returns the size of the list or negative value if something
**	went wrong. First argument is the concatenated list, and the second arg
**	is the adress of the final list made of int value.
*/
int	parse_arg(char *arg, int **final_list)
{
	char	**tmp_list;
	int		i;
	int		r_value;
	
	tmp_list = NULL;
	i = 0;
	r_value = 0;
	tmp_list = ft_split(arg, ' ');
	while (tmp_list[i])
		i++;
	*final_list = malloc(sizeof(int) * i);
	if (*final_list == NULL)
		return (free_tmp_list(tmp_list, -2));
	i = -1;
	while (tmp_list[++i])
		if (ft_atoi_spe(tmp_list[i], &((*final_list)[i])) < 0)
			return (free_tmp_list(tmp_list, -1));
	free_tmp_list(tmp_list, 0);
	return (i);
}
