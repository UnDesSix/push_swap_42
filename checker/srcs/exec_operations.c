#include "../includes/checker.h"

int	exec_operation(t_stack *stack_a, t_stack *stack_b, char *ope)
{
	if (ft_strlen(ope) == 2 && !ft_strncmp("sa", ope, 2))
		single_swap(stack_a);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("sb", ope, 2))
		single_swap(stack_b);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("ss", ope, 2))
		double_swap(stack_a, stack_b);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("pa", ope, 2))
		push_ope(stack_b, stack_a);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("pb", ope, 2))
		push_ope(stack_a, stack_b);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("ra", ope, 2))
		single_rotate(stack_a);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("rb", ope, 2))
		single_rotate(stack_b);
	else if (ft_strlen(ope) == 2 && !ft_strncmp("rr", ope, 2))
		double_rotate(stack_a, stack_b);
	else if (ft_strlen(ope) == 3 && !ft_strncmp("rra", ope, 3))
		single_reverse(stack_a);
	else if (ft_strlen(ope) == 3 && !ft_strncmp("rrb", ope, 3))
		single_reverse(stack_b);
	else if (ft_strlen(ope) == 3 && !ft_strncmp("rrr", ope, 3))
		double_reverse(stack_a, stack_b);
	return (0);
}
