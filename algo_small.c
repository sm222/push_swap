/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:40:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/13 17:59:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	item_3(t_ps **a)
{
	if ((*a)->i > (*a)->next->i && (*a)->next->i > (*a)->next->next->i)
	{
		rr(a, NULL);
		ss(a, NULL);
	}
	else if ((*a)->i > (*a)->next->i && (*a)->next->i < (*a)->next->next->i)
	{
		ss(a, NULL);
	}
}

void	small_algo(t_piles *data, size_t item)
{
	if (item == 2)
	{
		if (data->a->i > data->a->next->i)
			ss(&data->a, NULL);
	}
	if (item == 3)
		item_3(&data->a);
}
