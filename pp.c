/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:22:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/09 14:15:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps **a, t_ps **b)
{
	t_ps	*tmp_a;
	t_ps	*tmp_b;

	if (b && (*b))
	{
		tmp_b = (*b)->next;
		tmp_a = (*a);
		(*a) = (*b);
		(*a)->next = tmp_a;
		(*b) = tmp_b;
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_ps **a, t_ps **b)
{
	t_ps	*tmp_a;
	t_ps	*tmp_b;

	if (a && *a)
	{
		tmp_a = (*a)->next;
		tmp_b = (*b);
		(*b) = (*a);
		(*b)->next = tmp_b;
		(*a) = tmp_a;
		ft_putendl_fd("pb", 1);
	}
}

void	pp(t_ps **src, t_ps **dst, char *cmd)
{
	t_ps	*tmp_src;
	t_ps	*tmp_dst;

	if (src && *src)
	{
		tmp_src = (*src)->next;
		tmp_dst = (*dst);
		(*dst) = (*src);
		(*dst)->next = tmp_dst;
		(*src) = tmp_src;
		ft_putendl_fd(cmd, 1);
	}
}
