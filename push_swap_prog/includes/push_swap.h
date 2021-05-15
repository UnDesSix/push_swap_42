/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 08:40:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/15 09:07:28 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



# include <stdio.h>



# include <stdlib.h>
# include <unistd.h>
# include <../../libft/libft.h>

# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct	s_info
{
	int	min;
	int max;
	int med;
}				t_info;

typedef struct	s_stack
{
	int		*tab;
	int		cur_size;
	int		max_size;
	t_info	info;
}				t_stack;

int				ft_atoi_spe(const char *str, int *result);
int				*parse_arg(int list_size, char **argv);
t_bool			unique_values(int *list, int list_size);
t_bool			operation_is_valid(char *ope);
t_bool			list_is_sorted(t_stack stack_a);

int				create_stack_a(t_stack *stack_a, int *list, int list_size);
int				create_stack_b(t_stack *stack_b, int list_size);

int				ft_pa(t_stack *src, t_stack *dst);
int				ft_pb(t_stack *src, t_stack *dst);
int				ft_sa(t_stack *stack);
int				ft_sb(t_stack *stack);
int				ft_ss(t_stack *stack_a, t_stack *stack_b);
int				ft_ra(t_stack *stack);
int				ft_rb(t_stack *stack);
int				ft_rr(t_stack *stack_a, t_stack *stack_b);
int				ft_rra(t_stack *stack);
int				ft_rrb(t_stack *stack);
int				ft_rrr(t_stack *stack_a, t_stack *stack_b);

int				exec_operation(t_stack *stack_a, t_stack *stack_b, char *ope);

int				get_min_max_med(t_stack *stack_init);

int				sort_three(t_stack *stack_init, t_stack *stack_a);

#endif
