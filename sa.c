/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:07:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/07 10:11:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps *a, t_ps *b)
{
	if (a)
		s_p(a);
	if (b)
		s_p(b);
	if (a && b)
		ft_putendl_fd("ss", 2);
	else if (a)
		ft_putendl_fd("sa", 2);
	else if (b)
		ft_putendl_fd("sb", 2);
}

void	s_p(t_ps *node)
{
	t_ps	first;
	t_ps	mid;
	t_ps	last;

	if (node && node->next)
	{
		first = *node;
		mid = *node->next;
		last = *node->next->next;
		*node = mid;
		*node->next = first;
		*node->next->next = last;
	}
}
