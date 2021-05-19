/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 08:40:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/19 15:03:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



# include <stdio.h>
extern int ope_nb;

# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "./typedef_ps.h"
# define TRUE 1
# define FALSE 0

void	print_stacks(t_stack stack_a, t_stack stack_b);




int		ft_atoi_spe(const char *str, int *result);
int		*parse_arg(int list_size, char **argv);
t_bool	unique_values(int *list, int list_size);
t_bool	operation_is_valid(char *ope);
t_bool	list_is_sorted(t_stack stack_a);
t_bool	list_is_complete(t_stack stack_a);

int		create_stack_a(t_stack *stack_a, int *list, int list_size);
int		create_stack_b(t_stack *stack_b, int list_size);

int		ft_pa(t_stack *src, t_stack *dst);
int		ft_pb(t_stack *src, t_stack *dst);
int		ft_sa(t_stack *stack);
int		ft_sb(t_stack *stack);
int		ft_ss(t_stack *stack_a, t_stack *stack_b);
int		ft_ra(t_stack *stack);
int		ft_rb(t_stack *stack);
int		ft_rr(t_stack *stack_a, t_stack *stack_b);
int		ft_rra(t_stack *stack);
int		ft_rrb(t_stack *stack);
int		ft_rrr(t_stack *stack_a, t_stack *stack_b);

int		exec_operation(t_stack *stack_a, t_stack *stack_b, char *ope);

int		get_min_max_med(t_stack *stack_init);
int		bubble_sort(t_stack *stack_init);
int		stack_cpy(t_stack *src, t_stack *dst);

int		get_value_pos_top(int min, int max, t_stack *stack);
int		get_value_pos_bot(int min, int max, t_stack *stack);
int		get_value2_pos_top(int val1, int val2, t_stack *stack);
int		get_value2_pos_bot(int val1, int val2, t_stack *stack);

int		sort_three(t_stack *stack_a);
int		sort_five(t_stack *stack_a, t_stack *stack_b);
int		sort_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init);
int		qs_hundred(t_stack *stack_a, t_stack *stack_b, t_stack *stack_init);

t_chunk	*create_chunks(t_stack *stack_init, int chunk_size);

#endif
