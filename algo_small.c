/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:40:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/21 09:53:56 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	item_3(t_pile **a)
{
	if ((*a)->i > (*a)->next->i && (*a)->i < (*a)->next->next->i && \
	(*a)->next->i < (*a)->next->next->i)
		ss(a, NULL);
	if ((*a)->i > (*a)->next->i && (*a)->i > (*a)->next->next->i && \
	(*a)->next->i > (*a)->next->next->i)
		ss(a, NULL);
	if ((*a)->i < (*a)->next->i && (*a)->i < (*a)->next->next->i && \
	(*a)->next->i > (*a)->next->next->i)
		ss(a, NULL);
	if ((*a)->i > (*a)->next->i && (*a)->i > (*a)->next->next->i && \
	(*a)->next->i < (*a)->next->next->i)
		rr(a, NULL);
	if ((*a)->i < (*a)->next->i && (*a)->i > (*a)->next->next->i && \
	(*a)->next->i > (*a)->next->next->i)
		rrr(a, NULL);
}

void	item_4_or_5(t_piles *t_piles, size_t item)
{
	size_t	size_node;
	size_t	look;
	size_t	i;

	i = 1;
	while (i < item - 2)
	{	
		look = find_node_i((t_piles)->a, i);
		size_node = node_len((t_piles)->a) / 2;
		while ((t_piles)->a->i != i)
		{
			if (look < size_node / 2)
				rr(&t_piles->a, NULL);
			else
				rrr(&t_piles->a, NULL);
		}
		if (look_rest_a(&t_piles->a, item))
			return ;
		pp(&t_piles->a, &t_piles->b, "pb");
		i++;
	}
}

void	small_algo(t_piles *t_piles, size_t item)
{
	if (item == 1)
		return ;
	if (item == 2)
	{
		if (t_piles->a->i > t_piles->a->next->i)
			ss(&t_piles->a, NULL);
	}
	else if (item == 3)
		item_3(&t_piles->a);
	else if (item >= 4)
	{
		item_4_or_5(t_piles, item);
		item_3(&t_piles->a);
	}
}
