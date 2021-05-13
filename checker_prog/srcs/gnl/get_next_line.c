/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:09 by mlarboul          #+#    #+#             */
/*   Updated: 2021/05/11 17:52:06 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_lista	*begin_list = NULL;
	t_lista			*elm;
	int				return_val;

	elm = NULL;
	if (fd < 0 || !line || !BUFFER_SIZE || read(fd, NULL, 0) < 0)
		return (-1);
	if (!begin_list)
		if (!(begin_list = ft_create_elmem(fd)))
			return (-1);
	elm = begin_list;
	while (elm && elm->fd != fd)
		elm = elm->next;
	if (!elm)
		if (!(elm = ft_push_front(&begin_list, fd)))
			return (-1);
	if (!(*line = malloc(sizeof(char) + 1)))
		return (-1);
	(*line)[0] = '\0';
	elm->line_size = 0;
	if (!(return_val = ft_read_fd(elm, line)))
		ft_clear_elm(&begin_list, elm);
	return (return_val);
}

int		ft_read_fd(t_lista *elm, char **line)
{
	char	buffer[BUFFER_SIZE];
	int		read_bytes;
	int		return_val;

	return_val = 2;
	elm->buff_indx < elm->buff_size ? return_val = ft_fill_line(elm, line) : 0;
	while (return_val == 2)
	{
		(elm->buffer) ? free(elm->buffer) : 0;
		read_bytes = read(elm->fd, buffer, BUFFER_SIZE);
		if (!(elm->buffer = malloc(sizeof(char) * (read_bytes + 1))))
			return (-1);
		elm->buffer = ft_strncpy(elm->buffer, buffer, read_bytes);
		elm->buff_indx = 0;
		elm->buff_size = read_bytes;
		(elm->buff_size < BUFFER_SIZE && elm->fd) ? elm->flag_eof = 1 : 0;
		(!elm->buff_size && !(elm->fd)) ? elm->flag_eof = 1 : 0;
		return_val = ft_fill_line(elm, line);
	}
	return (return_val);
}

int		ft_fill_line(t_lista *elm, char **line)
{
	size_t	i;
	size_t	add_len;
	int		return_val;

	return_val = 2;
	if (elm->flag_eof && !elm->buff_size)
		return (0);
	i = elm->buff_indx;
	while (i < elm->buff_size && elm->buffer[i] != '\n')
		i++;
	(elm->buffer[i] == '\n') ? (return_val = 1) : 0;
	add_len = i - elm->buff_indx;
	*line = ft_realloc_spe(*line, elm->line_size, add_len);
	*line = ft_strncat(*line, elm->buffer + elm->buff_indx,
											elm->line_size, add_len);
	elm->line_size = elm->line_size + add_len;
	elm->buff_indx = i;
	(elm->buffer[i] == '\n') ? (elm->buff_indx = i + 1) : 0;
	if (elm->flag_eof && i == elm->buff_size)
		return_val = 0;
	return (return_val);
}

void	ft_clear_elm(t_lista **begin_list, t_lista *elm_to_del)
{
	t_lista	*elm;
	t_lista	*tmp;

	if (*begin_list == elm_to_del)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp->buffer);
		free(tmp);
		return ;
	}
	elm = (*begin_list);
	while (elm->next != elm_to_del)
		elm = elm->next;
	elm->next = elm_to_del->next;
	free(elm_to_del->buffer);
	free(elm_to_del);
}
