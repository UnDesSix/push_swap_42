/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_ps.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:18:26 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/16 10:19:38 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_PS_H
# define TYPEDEF_PS_H

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

typedef struct	s_chunk
{
	int	min_val;
	int max_val;
	int size;
	int	number;
}				t_chunk;

#endif
