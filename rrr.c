/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:22:05 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/12 12:54:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_top(t_ps **p)
{
	t_ps	*new_last;
	t_ps	*new_top;

	if ((*p) && (*p)->next)
	{
		new_last = return_index_node(p, node_len((*p)) - 1);
		new_top = new_last->next;
		new_top->next = (*p);
		(*p) = new_top;
		new_last->next = NULL;
		return (1);
	}
	return (0);
}

void	rrr(t_ps **a, t_ps **b)
{
	if (a && b)
	{
		if (r_top(a) && r_top(b))
			ft_putendl_fd("rrr", 1);
	}
	else if (a)
	{
		if (r_top(a))
			ft_putendl_fd("rra", 1);
	}
	else if (b)
	{
		if (r_top(b))
			ft_putendl_fd("rrb", 1);
	}
}
