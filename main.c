/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/07 17:46:55 by anboisve         ###   ########.fr       */
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

int	main(void)
{
	t_piles	piles;
	int		i;

	i = 1;
	piles.a = NULL;
	piles.b = NULL;
	while (i < 6)
		make_node_last(&piles.a, i++);
	print_pile(piles.a, 'a');
	print_pile(piles.b, 'b');
	ss(piles.a, NULL);
	//pa(&piles.a, &piles.b);
	printf("\n");
	ra(&piles.a);
	print_pile(piles.a, 'a');
	print_pile(piles.b, 'b');
	//pb(&piles.a, &piles.b);
	return (0);
}
