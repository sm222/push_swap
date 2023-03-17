/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:07:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 09:59:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_p(t_pile **node)
{
	t_pile	*first;
	t_pile	*mid;
	t_pile	*last;

	if (*node && (*node)->next)
	{
		first = (*node);
		mid = (*node)->next;
		last = (*node)->next->next;
		*node = mid;
		(*node)->next = first;
		(*node)->next->next = last;
	}
}

/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps.
*/
void	ss(t_pile **a, t_pile **b)
{
	if (a && b)
	{
		ft_putendl_fd("ss", 1);
		s_p(a);
		s_p(b);
	}
	else if (a)
	{
		ft_putendl_fd("sa", 1);
		s_p(a);
	}
	else if (b)
	{
		s_p(b);
		ft_putendl_fd("sb", 1);
	}
}
