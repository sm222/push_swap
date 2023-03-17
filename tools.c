/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:55:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 09:58:47 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_t_pile(t_pile	*data, char name)
{
	t_pile	*tmp;

	tmp = data;
	printf("%c size = %zu\n", name, node_len(tmp));
	while (tmp)
	{
		printf("%d %zu\n", tmp->data, tmp->i);
		tmp = tmp->next;
	}
	printf("\n");
}
