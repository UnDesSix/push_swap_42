/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 07:41:33 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/16 08:53:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_chunk	*get_chunks_nb(int list_size, int chunk_size)
{
	t_chunk	*chunks;
	int		chunks_nb;
	int		i;

	if (chunk_size < 1)
		return (NULL);
	chunks_nb = list_size / chunk_size;
	if (list_size % chunk_size > 0)
		chunks_nb++;
	chunks = malloc(sizeof(t_chunk) * chunk_size);
	if (chunks == NULL)
		return (NULL);
	i = 0;
	while (i < chunk_size)
	{
		chunks[i].number = chunks_nb;
		i++;
	}
	return (chunks);
}

t_chunk *create_chunks(t_stack *stack_init, int chunk_size)
{
	t_chunk	*chunks;
	int		i;

	bubble_sort(stack_init);
	chunks = get_chunks_nb(stack_init->max_size, chunk_size);
	if (chunks == NULL)
		return (NULL);
	i = 0;
	while (i < chunks[0].number)
	{
		chunks[i].min_val = stack_init->tab[i * chunk_size];
		if (stack_init->max_size / chunk_size == i)
		{
			chunks[i].size = stack_init->max_size % chunk_size;
			chunks[i].max_val = stack_init->tab[i * chunk_size
								+ stack_init->max_size % chunk_size - 1];
		}
		else
		{
			chunks[i].size = chunk_size;
			chunks[i].max_val = stack_init->tab[i * chunk_size + chunk_size - 1];
		}
		i++;
	}
	return (chunks);
}
