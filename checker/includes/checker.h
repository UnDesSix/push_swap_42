/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 06:58:32 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 17:16:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <../../libft/libft.h>
# include "get_next_line.h"
# define TRUE 1
# define FALSE 0
# define SHIFT_UP  1
# define SHIFT_DOWN 0exec_operation(t_stack *stack_a, t_stack *stack_b, char *ope)


typedef int		t_bool;

typedef struct	s_stack
{
	int		*tab;
	int		cur_size;
	int		max_size;
}				t_stack;

int				ft_atoi_spe(const char *str, int *result);
int				parse_arg(char *arg, int **final_list);
t_bool			unique_values(int *list, int list_size);
t_bool			operation_is_valid(char *ope);
t_bool			list_is_sorted(t_stack stack_a);

int				create_stack_a(t_stack *stack_a, int *list, int list_size);
int				create_stack_b(t_stack *stack_b, int list_size);

int				single_swap(t_stack *stack);
int				double_swap(t_stack *stack_a, t_stack *stack_b);
int				push_ope(t_stack *src, t_stack *dst);
int				single_rotate(t_stack *stack);
int				single_reverse(t_stack *stack);
int				double_rotate(t_stack *stack_a, t_stack *stack_b);
int				double_reverse(t_stack *stack_a, t_stack *stack_b);

int				exec_operation(t_stack *stack_a, t_stack *stack_b, char *ope);

#endif
