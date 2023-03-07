/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/07 11:37:09 by anboisve         ###   ########.fr       */
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

int	main(void)
{
	t_piles	piles;
	int		i;

	i = 0;
	piles.a = NULL;
	piles.b = NULL;
	while (i < 6)
		make_node_last(&piles.a, i++);
	i = 6;
	while (i < 11)
		make_node_last(&piles.b, i++);
	printf("a size = %zu\n", node_len(piles.a));
	printf("b size = %zu\n", node_len(piles.b));
	ss(piles.a, NULL);
	printf("\n");
	while (piles.a)
	{
		printf("a = %d\n", piles.a->data);
		piles.a = piles.a->next;
	}
	printf("\n");
	while (piles.b)
	{
		printf("b = %d\n", piles.b->data);
		piles.b = piles.b->next;
	}
	return (0);
}
