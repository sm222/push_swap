/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:58:58 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/07 17:59:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps **a)
{
	t_ps	*tmp_top;
	t_ps	*old_top;
	t_ps	*last;
	size_t	size;

	if (*a)
	{
		tmp_top = (*a);
		old_top = (*a);
		size = node_len(*a);
		while (--size)
			tmp_top = tmp_top->next;
		last = tmp_top;
		last->next = old_top;
		(*a) = last;
	}
}
