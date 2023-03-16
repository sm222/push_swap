/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:40:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/16 17:54:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	item_3(t_ps **a)
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

void	item_4_or_5(t_piles *piles, size_t item)
{
	size_t	size_node;
	size_t	look;
	size_t	i;

	i = 1;
	while (i < item - 2)
	{	
		look = find_node_i((piles)->a, i);
		size_node = node_len((piles)->a) / 2;
		while ((piles)->a->i != i)
		{
			if (look < size_node / 2)
				rr(&piles->a, NULL);
			else
				rrr(&piles->a, NULL);
		}
		if (look_rest_a(&piles->a, item))
			return ;
		pp(&piles->a, &piles->b, "pb");
		i++;
	}
}

void	small_algo(t_piles *piles, size_t item)
{
	if (item == 2)
	{
		if (piles->a->i > piles->a->next->i)
			ss(&piles->a, NULL);
	}
	if (item == 3)
		item_3(&piles->a);
	else if (item <= 6)
	{
		item_4_or_5(piles, item);
		item_3(&piles->a);
	}
}
