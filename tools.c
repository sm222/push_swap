/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:55:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/23 17:41:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile	*data, char name)
{
	t_pile	*tmp;

	tmp = data;
	ft_printf("%c size = %d\n", name, node_len(tmp));
	while (tmp)
	{
		ft_printf("%d %d\n", tmp->data, tmp->i);
		tmp = tmp->next;
	}
	ft_printf("\n");
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
			if (ft_isdigit(data[i][j]) && data[i][j + 1] != '-')
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

int	look_double(t_pile **head)
{
	t_pile	*tmp;
	t_pile	*seek;
	size_t	i;
	size_t	size;

	i = 1;
	size = node_len((*head));
	while (i < size)
	{
		tmp = return_index_node(head, i);
		seek = return_index_node(head, i + 1);
		while (seek)
		{
			if (seek->data != tmp->data)
				seek = seek->next;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
