/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:58:58 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/08 14:28:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps **a, t_ps **b)
{
	if (a && b)
	{
		if (r_r(a) && r_r(b))
			ft_putendl_fd("rr", 1);
	}
	else if (a)
	{
		if (r_r(a))
			ft_putendl_fd("ra", 1);
	}
	else if (b)
	{
		if (r_r(b))
			ft_putendl_fd("rb", 1);
	}
}

int	r_r(t_ps **p)
{
	t_ps	*new_top;
	t_ps	*last;
	size_t	size;

	if (*p && (*p)->next)
	{
		new_top = (*p)->next;
		last = (*p);
		size = node_len((*p));
		while (--size)
			last = last->next;
		last->next = (*p);
		(*p)->next = NULL;
		(*p) = new_top;
		return (1);
	}
	return (0);
}
