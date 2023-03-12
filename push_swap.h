/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:34:54 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/12 16:28:31 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_ft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_ps
{
	int			data;
	int			chek;
	size_t		i;
	struct s_ps	*next;

}	t_ps;

typedef struct s_piles
{
	t_ps	*a;
	t_ps	*b;

}	t_piles;

size_t	node_len(t_ps *node);
void	ss(t_ps **a, t_ps **b);
void	pa(t_ps **a, t_ps **b);
void	pb(t_ps **a, t_ps **b);
void	rr(t_ps **a, t_ps **b);
int		r_r(t_ps **p);
t_ps	*return_last_node(t_ps **head);
t_ps	*return_index_node(t_ps **head, size_t i);
void	rrr(t_ps **a, t_ps **b);
void	print_pile(t_ps	*data, char name);
void	pp(t_ps **src, t_ps **dst, char *cmd);
t_ps	*make_node(int data);
void	make_node_last(t_ps **node, int data);
void	bot_or_up_a(t_ps **a, t_ps **b, int i);
size_t	find_node_i(t_ps *head, size_t i);
void	make_bucket(t_ps **a, t_ps **b, int bucket, size_t last);

#endif 
