/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:53:39 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/13 08:55:20 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
**DEBUG
**void	print_stacks(t_stack stack_a, t_stack stack_b)
**{
**	printf("STACK_A :\n");
**	if (stack_a.cur_size == 0)
**		printf("[EMPTY]\n");
**	for (int i = 0; i < stack_a.cur_size; i++)
**		printf("[%3d]: %3d\n", i, stack_a.tab[i]);
**	printf("\nSTACK_B :\n");
**	if (stack_b.cur_size == 0)
**		printf("[EMPTY]\n");
**	for (int i = 0; i < stack_b.cur_size; i++)
**		printf("[%3d]: %3d\n", i, stack_b.tab[i]);
**}
**
**DEBUG
**void	print_list(int list_size, int *list)
**{
**	for (int i = 0; i < list_size; i++)
**		printf("value %3d : %3d\n", i, list[i]);
**}
*/

int		ft_error(int *list)
{
	write(1, "KO\n", 3);
	if (list != NULL)
		free(list);
	return (0);
}

int		read_operations(t_stack *stack_a, t_stack *stack_b)
{
	int		success;
	char	*line;

	success = TRUE;
	while (get_next_line(0, &line) != 0)
	{
		if (operation_is_valid(line) == FALSE)
			success = FALSE;
		else
			exec_operation(stack_a, stack_b, line);
		if (line != NULL)
			free(line);
	}
	if (line != NULL)
		free(line);
	if (success == FALSE)
	{
		write(1, "KO\n", 3);
		free(stack_a->tab);
		free(stack_b->tab);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		*list;
	int		list_size;
	t_stack	stack_a;
	t_stack	stack_b;

	list_size = argc - 1;
	list = parse_arg(list_size, argv);
	if (!list || unique_values(list, list_size) == FALSE)
		return (ft_error(list));
	create_stack_a(&stack_a, list, list_size);
	create_stack_b(&stack_b, list_size);
	free(list);
	if (read_operations(&stack_a, &stack_b) < 0)
		return (0);
	if (list_is_sorted(stack_a) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
