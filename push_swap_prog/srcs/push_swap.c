/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:56:09 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/13 13:20:36 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/push_swap.h"

int		ft_error(int *list)
{
	write(1, "Error\n", 6);
	if (list != NULL)
		free(list);
	return (-1);
}

int	check_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		*list;
	int		list_size;

	if (argc < 2)
		return (-1);
	list_size = argc - 1;
	list = parse_arg(list_size, argv);
	if (!list || unique_values(list, list_size) == FALSE)
		return (ft_error(list));
	if (create_stack_a(stack_a, list, list_size) < 0
			|| create_stack_b(stack_b, list_size) < 0)
		return (ft_error(list));
	if (list != NULL)
		free(list);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (check_args(argc, argv, &stack_a, &stack_b) < 0)
		return (0);
	printf("list is ok\n");
	return (0);
}
