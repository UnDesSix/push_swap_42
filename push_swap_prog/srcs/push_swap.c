/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:56:09 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/20 10:11:13 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
//	void	print_stacks(t_stack stack_a, t_stack stack_b, char *str)
//	{
//		printf("\n---------------- ");
//		printf("(%s)\n\n", str);
//		printf("STACK_A :\n");
//		if (stack_a.cur_size == 0)
//			printf("[EMPTY]\n");
//		for (int i = 0; i < stack_a.cur_size; i++)
//			printf("[%3d]: %3d\n", i, stack_a.tab[i]);
//		printf("\nSTACK_B :\n");
//		if (stack_b.cur_size == 0)
//			printf("[EMPTY]\n");
//		for (int i = 0; i < stack_b.cur_size; i++)
//			printf("[%3d]: %3d\n", i, stack_b.tab[i]);
//	}
*/

int	ft_free_stacks(t_stack stack_a, t_stack stack_b, t_stack stack_init)
{
	if (stack_a.tab != NULL)
		free(stack_a.tab);
	if (stack_b.tab != NULL)
		free(stack_b.tab);
	if (stack_init.tab != NULL)
		free(stack_init.tab);
	return (0);
}

int	ft_error(int *list)
{
	write(1, "Error\n", 6);
	if (list != NULL)
		free(list);
	return (-1);
}

int	check_args(char **argv, t_stack *stack_init,
				t_stack *stack_a, t_stack *stack_b)
{
	int		list_size;

	if (stack_init->max_size < 1)
		return (-1);
	list_size = stack_init->max_size;
	stack_init->tab = parse_arg(list_size, argv);
	if (!stack_init->tab || unique_values(stack_init->tab, list_size) == FALSE)
		return (ft_error(stack_init->tab));
	if (create_stack_a(stack_a, stack_init->tab, list_size) < 0
		|| create_stack_b(stack_b, list_size) < 0)
		return (ft_error(stack_init->tab));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_init;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_init.max_size = argc - 1;
	if (check_args(argv, &stack_init, &stack_a, &stack_b) < 0)
		return (0);
	if (list_is_sorted(stack_a) == TRUE && list_is_complete(stack_a))
		;
	else if (stack_init.max_size <= 3)
		sort_three(&stack_a);
	else if (stack_init.max_size <= 5)
		sort_five(&stack_a, &stack_b);
	else if (stack_init.max_size <= 100)
		qs_hundred(&stack_a, &stack_b, &stack_init, 25);
	else
		qs_hundred(&stack_a, &stack_b, &stack_init, 90);
	ft_free_stacks(stack_a, stack_b, stack_init);
	return (0);
}
