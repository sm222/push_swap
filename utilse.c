/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:43:28 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/16 10:30:38 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*return_index_node(t_ps **head, size_t i)
{
	t_ps	*tmp;
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

size_t	find_node_i(t_ps *head, size_t i)
{
	size_t	index;
	t_ps	*tmp;

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

void	free_node(t_ps **a, t_ps **b)
{
	t_ps	*tmp;
	t_ps	*next;

	tmp = (*a);
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = (*b);
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	exit(0);
}
