/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:55:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/09 10:59:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_ps	*data, char name)
{
	t_ps	*tmp;

	tmp = data;
	printf("%c size = %zu\n", name, node_len(tmp));
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
