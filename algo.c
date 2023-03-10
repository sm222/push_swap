/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:27:08 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/10 13:44:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bot_or_up(t_ps **head, int i)
{
	size_t	look;
	size_t	size_node;

	look = find_node_i((*head), i);
	size_node = node_len((*head)) / 2;
	if (look <= size_node)
		rr(head, NULL);
	else
		rrr(head, NULL);
}
