/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:43:28 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/23 11:08:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char ***data, int exit_f)
{
	size_t	i;

	i = 0;
	while (data && data[i])
		ft_double_sfree((void **)data[i++]);
	if (data)
		free(data);
	if (exit_f)
	{
		if (exit_f == 2)
			ft_putendl_fd("error", 2);
		exit(1);
	}
}

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

int	while_number(char **data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (ft_isdigit(data[i][j]))
				j++;
			else if (data[i][j] == '-' && ft_isdigit(data[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
