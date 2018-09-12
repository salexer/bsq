/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btion-fr <btion-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:38:59 by btion-fr          #+#    #+#             */
/*   Updated: 2018/09/12 20:39:00 by btion-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void				ft_puterr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(2, &str[i++], 1);
}

unsigned int		ft_bsq_find_min_weight(unsigned int a,
						unsigned int b, unsigned int c)
{
	unsigned int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}
