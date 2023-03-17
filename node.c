/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:22:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 12:35:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_pile *a, t_pile *b)
{
	t_pile	*tmp;
	t_pile	*next;

	tmp = a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = b;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	exit(0);
}

size_t	find_next_big(t_pile **head)
{
	size_t	i;
	t_pile	*tmp;

	i = 0;
	tmp = (*head);
	while (tmp)
	{
		if (i < tmp->i)
			i = tmp->i;
		tmp = tmp->next;
	}
	return (i);
}

size_t	node_len(t_pile *node)
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

t_pile	*make_node(int data)
{
	t_pile	*tmp;

	tmp = ft_calloc(1, sizeof(t_pile));
	tmp->data = data;
	tmp->chek = 0;
	return (tmp);
}

void	make_node_last(t_pile **node, int data)
{
	size_t	size;
	t_pile	*tmp;

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
		free_node((*node), NULL);
}
