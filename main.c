/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/09 17:28:29 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_node_last(t_ps **node, int data)
{
	size_t	size;
	t_ps	*tmp;

	size = node_len(*node);
	if (size == 0)
	{
		(*node) = make_node(data);
		return ;
	}
	tmp = (*node);
	while (--size)
		tmp = tmp->next;
	tmp->next = make_node(data);
}

int	main(int ac, char **av)
{
	t_piles		piles;
	int			i;
	long		big;

	big = LONG_MAX;
	i = 0;
	piles.a = NULL;
	piles.b = NULL;
	while (++i < ac)
		make_node_last(&piles.a, ft_atoi(av[i]));
	while (node_len(piles.a))
	{
		if (big == piles.a->data)
		{
			big = LONG_MAX;
			pp(&piles.a, &piles.b, "pb");
		}
		else if (big > piles.a->data)
			big = piles.a->data;
		rr(&piles.a, NULL);
	}
	while (node_len(piles.b))
		pp(&piles.b, &piles.a, "pa");
	return (0);
}
