/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:34:54 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 12:41:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_ft/libft.h"
# include <limits.h>

typedef struct s_ps
{
	size_t		i;
	int			data;
	int			chek;
	struct s_ps	*next;

}	t_pile;

typedef struct s_piles
{
	t_pile	*a;
	t_pile	*b;

}	t_piles;

typedef struct s_data
{
	int			i;
	size_t		item;
	char		**numbers;
}	t_data;

//instructuon

int		r_r(t_pile **p);
void	ss(t_pile **a, t_pile **b);
void	rr(t_pile **a, t_pile **b);
void	rrr(t_pile **a, t_pile **b);
void	pp(t_pile **src, t_pile **dst, char *cmd);

//utils
t_pile	*make_node(int data);
size_t	node_len(t_pile *node);
void	free_node(t_pile *a, t_pile *b);
void	free_node(t_pile *a, t_pile *b);
t_pile	*return_last_node(t_pile **head);
size_t	find_node_i(t_pile *head, size_t i);
void	make_node_last(t_pile **node, int data);
t_pile	*return_index_node(t_pile **head, size_t i);

//algo
size_t	find_next_big(t_pile **head);
void	small_algo(t_piles *piles, size_t item);
int		look_rest_a(t_pile **head, size_t last);
void	move_piles(t_pile **a, t_pile **b, int i);
void	make_bucket(t_pile **a, t_pile **b, int bucket, size_t last);

void	print_pile(t_pile	*data, char name);

#endif 
