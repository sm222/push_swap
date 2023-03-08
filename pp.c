/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:22:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/08 13:18:14 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps **a, t_ps **b)
{
	t_ps	*tmp_a;
	t_ps	*tmp_b;

	if (*b != NULL)
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
