/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:43:28 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 12:34:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*return_index_node(t_pile **head, size_t i)
{
	t_pile	*tmp;
	size_t	size;

	if (head && *head)
	{
		tmp = (*head);
		size = node_len(tmp);
		if (size == 0)
			return (NULL);
		while (--size && --i)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

t_pile	*return_last_node(t_pile **head)
{
	t_pile	*tmp;
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

size_t	find_node_i(t_pile *head, size_t i)
{
	size_t	index;
	t_pile	*tmp;

	tmp = head;
	index = 0;
	while (tmp)
	{
		if (tmp->i == i)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}
