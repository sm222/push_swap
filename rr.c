/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:58:58 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 09:58:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_pile **a, t_pile **b)
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

int	r_r(t_pile **p)
{
	t_pile	*new_top;
	t_pile	*last;

	if (*p && (*p)->next)
	{
		new_top = (*p)->next;
		last = return_last_node((p));
		last->next = (*p);
		(*p)->next = NULL;
		(*p) = new_top;
		return (1);
	}
	return (0);
}
