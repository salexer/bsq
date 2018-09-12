/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btion-fr <btion-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:38:34 by btion-fr          #+#    #+#             */
/*   Updated: 2018/09/12 20:38:36 by btion-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq		*ft_bsq_init(t_bsq *bsq)
{
	ft_bsq_free(bsq);
	bsq = (t_bsq *)malloc(sizeof(t_bsq));
	bsq->lines = 0;
	bsq->columns = 0;
	bsq->column = 0;
	bsq->line = 0;
	bsq->square = 0;
	bsq->squarei = 0;
	bsq->empty = 0;
	bsq->obstacle = 0;
	bsq->full = 0;
	bsq->weights = 0;
	bsq->map = 0;
	bsq->list = 0;
	return (bsq);
}

void		ft_bsq_free(t_bsq *bsq)
{
	if (bsq)
	{
		if (bsq->weights)
			free(bsq->weights);
		if (bsq->map)
			free(bsq->map);
		if (bsq->list)
			free(bsq->list);
		bsq->weights = 0;
		bsq->map = 0;
		bsq->list = 0;
		free(bsq);
		bsq = 0;
	}
}

short		ft_bsq_init_options(t_bsq *bsq, char *options, unsigned short size)
{
	short			i;
	unsigned long	lines;

	bsq->full = options[size - 1];
	bsq->obstacle = options[size - 2];
	bsq->empty = options[size - 3];
	i = 0;
	lines = 0;
	while (i < size - 3)
	{
		if (options[i] >= '0' && options[i] <= '9')
			lines = lines * 10 + (options[i] - '0');
		else
			return (0);
		i++;
	}
	bsq->lines = (unsigned int)lines;
	return (bsq->lines > 0
			&& bsq->empty != bsq->obstacle
			&& bsq->obstacle != bsq->full
			&& bsq->empty != bsq->full);
}

short		ft_bsq_init_vectors(t_bsq *bsq)
{
	if (!bsq->weights)
		bsq->weights = malloc(sizeof(bsq->weights) * 2 * bsq->columns);
	if (!bsq->weights)
		return (0);
	if (bsq->list)
		ft_bsq_list_merge(bsq);
	if (!bsq->map)
		bsq->map = malloc(sizeof(bsq->map) *
				(bsq->columns * bsq->lines + bsq->lines + 1));
	if (!bsq->map)
		return (0);
	return (1);
}

void		ft_bsq_write_vector(t_bsq *bsq, char buffer)
{
	unsigned int	pos;

	if (buffer == '\n')
	{
		bsq->map[bsq->columns + (bsq->line - 1) * (bsq->columns + 1)] = buffer;
		return ;
	}
	pos = bsq->column + bsq->j;
	bsq->map[bsq->column + bsq->line * (bsq->columns + 1)] = buffer;
	if (buffer == bsq->obstacle)
		bsq->weights[pos] = 0;
	else if (bsq->column == 0 || bsq->line == 0)
		bsq->weights[pos] = 1;
	else if (bsq->line > 0)
		bsq->weights[pos] = 1 + ft_bsq_find_min_weight(bsq->weights[pos - 1],
				bsq->weights[pos + bsq->k * bsq->columns],
				bsq->weights[pos + bsq->k * bsq->columns - 1]);
	if (bsq->weights[pos] > bsq->square)
	{
		bsq->square = bsq->weights[pos];
		bsq->squarei = bsq->column + bsq->line * (bsq->columns + 1);
	}
}
