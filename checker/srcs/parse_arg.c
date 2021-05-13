/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:43:12 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/13 07:49:36 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		free_tmp_list(char **tmp_list, int err_code)
{
	int	i;

	i = 0;
	while (tmp_list[i])
		free(tmp_list[i++]);
	free(tmp_list);
	return (err_code);
}

/*
**	This function returns the list malloc'd or NULL pointers if something
**	went wrong. First argument is the size of the list, and the second arg
**	is the adress of the tab containing all arguments.
*/

int		*parse_arg(int list_size, char **argv)
{
	int	i;
	int	*list;

	if (list_size < 1)
		return (NULL);
	i = 0;
	list = malloc(sizeof(int) * (list_size));
	if (list == NULL)
		return (NULL);
	while (i < list_size)
	{
		if (ft_atoi_spe(argv[i + 1], &list[i]) < 0)
		{
			printf("ERROR\n");
			return (NULL);
		}
		i++;
	}
	return (list);
}

/*
**	This function check if all the value are different from each other.
**	If so it returns TRUE, else it returns FALSE
*/

t_bool	unique_values(int *list, int list_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < list_size)
	{
		j = i + 1;
		while (j < list_size)
		{
			if (list[i] == list[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
