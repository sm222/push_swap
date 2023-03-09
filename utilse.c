/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:43:28 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/09 16:36:01 by anboisve         ###   ########.fr       */
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

t_ps	*return_index_node(t_ps **head, size_t i)
{
	t_ps	*tmp;
	size_t	size;

	if (!head)
		return (NULL);
	if (*head)
	{
		tmp = (*head);
		size = node_len(tmp);
		while (--size && --i)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

t_ps	*return_last_node(t_ps **head)
{
	t_ps	*tmp;
	size_t	size;

	if (!head)
		return (NULL);
	if (*head)
	{
		tmp = (*head);
		size = node_len(tmp);
		while (--size)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

t_ps	*make_node(int data)
{
	t_ps	*tmp;

	tmp = ft_calloc(1, sizeof(t_ps));
	tmp->data = data;
	return (tmp);
}
