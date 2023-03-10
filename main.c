/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/10 17:42:29 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	pile_set_index(t_ps **head)
{
	t_ps	*tmp;
	int		small;
	size_t	i;

	i = 0;
	tmp = (*head);
	small = INT32_MAX;
	while (i < node_len(tmp))
	{
		while (tmp)
		{
			if (tmp->chek == 0 && tmp->data == small)
			{
				tmp->chek = 1;
				small = INT32_MAX;
				tmp->i = ++i;
			}
			else if (tmp->chek == 0 && tmp->data < small)
				small = tmp->data;
			tmp = tmp->next;
		}
		tmp = (*head);
	}
	return (i);
}

int	look_rest_a(t_ps **head)
{
	t_ps	*tmp;

	tmp = (*head);
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->i < tmp->next->i)
				tmp = tmp->next;
			else
				return (0);
		}
		else
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_piles		piles;
	size_t		ammount;
	int			i;

	i = 0;
	piles.a = NULL;
	piles.b = NULL;
	while (++i < ac)
		make_node_last(&piles.a, ft_atoi(av[i]));
	ammount = pile_set_index(&piles.a);
	i = 1;
	while (node_len(piles.a))
	{
		if (look_rest_a(&piles.a))
			break ;
		if (piles.a->i == (size_t)i)
		{
			pp(&piles.a, &piles.b, "pb");
			i++;
			continue ;
		}
		bot_or_up(&piles.a, i);
	}
	while (node_len(piles.b))
		pp(&piles.b, &piles.a, "pa");
	return (0);
}
