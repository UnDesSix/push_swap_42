/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 06:58:32 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 08:11:12 by mlarboul         ###   ########.fr       */
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

typedef int		t_bool;

typedef struct	s_stack
{
	int		*tab;
	int		curr_size;
	int		tot_size;
}				t_stack;

int				ft_atoi_spe(const char *str, int *result);
int				parse_arg(char *arg, int **final_list);
t_bool			unique_values(int *list, int list_size);
t_bool			operation_is_valid(char *ope);
t_bool			list_is_sorted(int *list, int list_size);

#endif
