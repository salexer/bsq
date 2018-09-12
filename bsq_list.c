/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btion-fr <btion-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:39:14 by btion-fr          #+#    #+#             */
/*   Updated: 2018/09/12 20:39:15 by btion-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq_list	*ft_bsq_create_elem(char *buffer)
{
	t_bsq_list		*list;
	unsigned int	i;

	list = malloc(sizeof(t_bsq_list));
	if (list)
	{
		i = 0;
		while (buffer[i] != '\0')
		{
			list->buffer[i] = buffer[i];
			i++;
		}
		list->buffer[i] = '\0';
		list->next = NULL;
	}
	return (list);
}

void		ft_bsq_list_push_back(t_bsq_list **begin_list, char *buffer)
{
	t_bsq_list	*list;
	t_bsq_list	*index;

	if (!begin_list)
		return ;
	list = *begin_list;
	index = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_bsq_create_elem(buffer);
		*begin_list = index;
	}
	else
		*begin_list = ft_bsq_create_elem(buffer);
}

void		ft_bsq_list_clear(t_bsq_list **begin_list)
{
	t_bsq_list	*list;
	t_bsq_list	*clear;

	if (!begin_list)
		return ;
	list = *begin_list;
	clear = NULL;
	while (list)
	{
		if (list->next)
			clear = list->next;
		else
			clear = NULL;
		free(list);
		list = clear;
	}
	*begin_list = NULL;
}

void		ft_bsq_list_merge(t_bsq *bsq)
{
	unsigned short	i;
	unsigned short	j;
	t_bsq_list		*list;

	if (!bsq || !bsq->weights || !bsq->list)
		return ;
	list = bsq->list;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->buffer[j] != '\0' && i < bsq->columns)
		{
			if (list->buffer[j] == '\n')
				continue ;
			bsq->weights[i++] = list->buffer[j] != bsq->obstacle;
			j++;
		}
		list = list->next;
	}
	bsq->column = i;
	ft_bsq_list_clear(&bsq->list);
}
