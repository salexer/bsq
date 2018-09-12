/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btion-fr <btion-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:38:48 by btion-fr          #+#    #+#             */
/*   Updated: 2018/09/12 20:38:49 by btion-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BSQ_MAP_ERROR "map error\n"
# define BSQ_BUFFER_LEN 1024
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct			s_bsq_list
{
	char				buffer[BSQ_BUFFER_LEN + 1];
	struct s_bsq_list	*next;
}						t_bsq_list;
typedef struct			s_bsq
{
	short				k;
	unsigned int		j;
	unsigned int		lines;
	unsigned int		line;
	unsigned int		square;
	unsigned int		squarei;
	unsigned int		column;
	unsigned int		columns;
	char				empty;
	char				obstacle;
	char				full;
	unsigned int		*weights;
	char				*map;
	t_bsq_list			*list;
}						t_bsq;
void					ft_putbsq(t_bsq *bsq);
t_bsq					*ft_bsq_init(t_bsq *bsq);
void					ft_bsq_free(t_bsq *bsq);
short					ft_bsq_init_options(t_bsq *bsq,
						char *options, unsigned short size);
short					ft_bsq_init_vectors(t_bsq *bsq);
void					ft_bsq_write_vector(t_bsq *bsq, char buffer);
t_bsq_list				*ft_bsq_create_elem(char *buffer);
void					ft_bsq_list_push_back(t_bsq_list **begin_list,
						char *buffer);
void					ft_bsq_list_clear(t_bsq_list **begin_list);
void					ft_bsq_list_merge(t_bsq *bsq);
short					ft_bsq_read_map(t_bsq *bsq, int fd);
short					ft_bsq_read_map_buffer(t_bsq *bsq, char *buffer);
short					ft_bsq_read_map_buffer_helper(t_bsq *bsq, char c);
short					ft_bsq_read_options(t_bsq *bsq, int fd);
short					ft_bsq_read_file(t_bsq *bsq, char *fname);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_puterr(char *str);
unsigned int			ft_bsq_find_min_weight(unsigned int a,
		unsigned int b, unsigned int c);

#endif
