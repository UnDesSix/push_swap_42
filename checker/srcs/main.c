/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 06:58:44 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 17:15:42 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_error(int code, int *final_list)
{
	if (code == 0)
		printf("Error arguments\n");
	else if (code == 1)
		printf("Error list\n");
	else if (code == 2)
		printf("Same number\n");
	if (final_list != NULL)
		free(final_list);
	return (0);
}

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	printf("STACK_A :\n");
	if (stack_a.cur_size == 0)
		printf("[EMPTY]\n");
	for (int i = 0; i < stack_a.cur_size; i++)
		printf("[%3d]: %3d\n", i, stack_a.tab[i]);
	printf("\nSTACK_B :\n");
	if (stack_b.cur_size == 0)
		printf("[EMPTY]\n");
	for (int i = 0; i < stack_b.cur_size; i++)
		printf("[%3d]: %3d\n", i, stack_b.tab[i]);
}


int		main(int argc, char **argv)
{
	int		success;
	int		*final_list;
	int		list_size;
	char	*line;
	t_stack	stack_a;
	t_stack	stack_b;

	success = TRUE;
	final_list = NULL;

	// CHECKING ERRORS
	if (argc != 2)
		return (ft_error(0, final_list));
	list_size = parse_arg(argv[1], &final_list);
	if (list_size < 0)
		return (ft_error(1, final_list));
	if (unique_values(final_list, list_size) == FALSE)
		return (ft_error(2, final_list));

	/*
	// PRINTING VALUES IF NO MISTAKE (aka : valid arg, unique values, integers only)
	for (int i = 0; i < list_size; i++)
		printf("value %3d : %3d\n", i, final_list[i]);
	*/


	// CREATING AND PRINTING STACKS
	create_stack_a(&stack_a, final_list, list_size);
	create_stack_b(&stack_b, list_size);	
	print_stacks(stack_a, stack_b);
	
	// ONLY WHEN STACKS ARE FILLED
	free(final_list);

	// READING OPERATIONS
	while (get_next_line(0, &line) != 0 && success == TRUE)
	{
//		if (operation_is_valid(line) == FALSE)
//			success = FALSE;
//		else
			exec_operation(&stack_a, &stack_b, line);
		if (line != NULL)
			free(line);
	}
	if (line != NULL)
		free(line);
	if (success == FALSE)
	{
		printf("Wrong operations\n");
		free(stack_a.tab);
		free(stack_b.tab);
		return (0);
	}
	
	// CHECKING IF THE LIST IS SORTED
	print_stacks(stack_a, stack_b);
	if (list_is_sorted(stack_a) == TRUE)
		printf("\nYEAAAAH Your list is well sorted!\n");
	else 
		printf("\nBOOOOOH Your list is not sorted...\n");

	// FREE STACKS

	free(stack_a.tab);
	free(stack_b.tab);
	return (0);
}
