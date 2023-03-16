/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/16 14:57:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	pile_set_index(t_ps **head)
{
	t_ps		*tmp;
	long		small;
	size_t		i;

	i = 0;
	tmp = (*head);
	small = 2147483648;
	while (i < node_len(tmp))
	{
		while (tmp)
		{
			if (tmp->chek == 0 && tmp->data == small)
			{
				tmp->chek = 1;
				small = 2147483648;
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

// ac / 5

void	find_next_b(t_ps **b, size_t i)
{
	size_t	look;
	size_t	size_node;

	look = find_node_i((*b), i);
	size_node = node_len((*b)) / 2;
	if (look <= size_node)
	{
		rr(NULL, b);
	}
	else
	{
		rrr(NULL, b);
	}
}

size_t	find_next_big(t_ps **head)
{
	size_t	i;
	t_ps	*tmp;

	i = 0;
	tmp = (*head);
	while (tmp)
	{
		if (i < tmp->i)
			i = tmp->i;
		tmp = tmp->next;
	}
	return (i);
}

void	b_to_a(t_ps **a, t_ps **b, size_t size)
{
	size = find_next_big((b));
	while (node_len(*b))
	{
		if ((*b)->i == size)
		{
			pp(b, a, "pa");
			size = find_next_big((b));
			continue ;
		}
		size = find_next_big((b));
		find_next_b(b, size);
	}
}

int	main(int ac, char **av)
{
	t_piles		piles;
	int			i;
	size_t		item;

	i = 1;
	piles.a = NULL;
	piles.b = NULL;
	if (ac == 2)
		av = ft_split(av[i--], ' ');
	while (av[i])
		make_node_last(&piles.a, ft_atoi(av[i++]));
	item = pile_set_index(&piles.a);
	if (item <= 5)
		small_algo(&piles, item);
	else if (item < 100)
		make_bucket(&piles.a, &piles.b, 1, item);
	else if (item < 300)
		make_bucket(&piles.a, &piles.b, item / 6, item);
	else
		make_bucket(&piles.a, &piles.b, item / 16, item);
	b_to_a(&piles.a, &piles.b, item);
	free_node(&piles.a, &piles.b);
	return (0);
}
