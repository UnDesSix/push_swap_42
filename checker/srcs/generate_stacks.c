#include "../includes/checker.h"

int		create_stack_b(t_stack *stack_b, int list_size)
{
	stack_b->tab = malloc(sizeof(int) * list_size);
	if (stack_b->tab == NULL)
		return (-1);
	stack_b->cur_size = 0;
	stack_b->max_size = list_size;
	return (0);
}

int		create_stack_a(t_stack *stack_a, int *list, int list_size)
{
	int i;

	i = 0;
	stack_a->tab = malloc(sizeof(int) * list_size);
	if (stack_a->tab == NULL)
		return (-1);
	while (i < list_size)
	{
		stack_a->tab[i] = list[i];
		i++;
	}
	stack_a->cur_size = list_size;
	stack_a->max_size = list_size;
	return (0);
}
