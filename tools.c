/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:55:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/21 09:49:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile	*data, char name)
{
	t_pile	*tmp;

	tmp = data;
	ft_printf("%c size = %d\n", name, node_len(tmp));
	while (tmp)
	{
		ft_printf("%d %d\n", tmp->data, tmp->i);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
