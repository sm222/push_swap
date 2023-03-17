/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:27:08 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 10:03:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_next_small(t_pile **head)
{
	size_t	i;
	t_pile	*tmp;

	i = -1;
	tmp = (*head);
	while (tmp)
	{
		if (i > tmp->i)
			i = tmp->i;
		tmp = tmp->next;
	}
	return (i);
}

int	look_rest_a(t_pile **head, size_t last)
{
	t_pile	*tmp;

	tmp = (*head);
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->i == tmp->next->i -1)
				tmp = tmp->next;
			else
				return (0);
			if (tmp->i == last && tmp->next == NULL)
				return (1);
		}
		else
			break ;
	}
	return (0);
}

void	move_piles(t_pile **a, t_pile **b, int i)
{
	size_t			look;
	size_t			size_node;
	t_pile			*tmp;
	static size_t	range = 15;

	tmp = return_last_node(b);
	look = find_node_i((*a), i);
	size_node = node_len((*a)) / 2;
	if ((*b) && tmp && (*b)->i > tmp->i && \
	(*b)->i < range < range && tmp->i < range)
		rr(a, b);
	else
		rr(a, NULL);
	range++;
}

void	make_bucket(t_pile **a, t_pile **b, int bucket, size_t last)
{
	size_t	i;

	i = find_next_small(a);
	while (node_len(*a))
	{
		if (look_rest_a(a, last))
			break ;
		if ((*a)->i >= (size_t)i && (*a)->i <= (size_t)i + bucket + 5)
		{
			pp(a, b, "pb");
			i = find_next_small(a);
			continue ;
		}
		move_piles(a, b, i);
	}
}
