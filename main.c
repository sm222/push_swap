/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/08 16:01:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*make_node(int data)
{
	t_ps	*tmp;

	tmp = ft_calloc(1, sizeof(t_ps));
	tmp->data = data;
	return (tmp);
}

size_t	node_len(t_ps *node)
{
	size_t	size;

	size = 1;
	if (!node)
		return (0);
	while (node)
	{
		node->i = size - 1;
		node = node->next;
		if (node)
			size++;
	}
	return (size);
}

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

void	print_pile(t_ps	*data, char name)
{
	t_ps	*tmp;

	tmp = data;
	printf("%c size = %zu\n", name, node_len(tmp));
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
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
			pb(&piles.a, &piles.b);
		}
		else if (big > piles.a->data)
			big = piles.a->data;
		rr(&piles.a, NULL);
	}
	while (node_len(piles.b))
		pa(&piles.a, &piles.b);
	return (0);
}
