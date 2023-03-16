/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:22:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/16 10:10:20 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	node_len(t_ps *node)
{
	size_t	size;

	size = 1;
	if (!node)
		return (0);
	while (node)
	{
		node = node->next;
		if (node)
			size++;
	}
	return (size);
}

t_ps	*make_node(int data)
{
	t_ps	*tmp;

	tmp = ft_calloc(1, sizeof(t_ps));
	tmp->data = data;
	tmp->chek = 0;
	return (tmp);
}

void	make_node_last(t_ps **node, int data)
{
	size_t	size;
	t_ps	*tmp;

	size = node_len(*node);
	if (size == 0)
	{
		(*node) = make_node(data);
		if (!*node)
			exit(1);
		return ;
	}
	tmp = (*node);
	while (--size)
		tmp = tmp->next;
	tmp->next = make_node(data);
	if (!tmp->next)
		free_node(node, NULL);
}
