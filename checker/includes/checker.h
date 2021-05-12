/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 06:58:32 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/12 07:10:06 by mlarboul         ###   ########.fr       */
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

typedef int	t_bool;

int		ft_atoi_spe(const char *str, int *result);
int		parse_arg(char *arg, int **final_list);
t_bool	unique_values(int *list, int list_nbr);
t_bool	operation_is_valid(char *ope);

#endif
