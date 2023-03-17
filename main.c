/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 17:49:00 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	t_pile_set_index(t_pile **head)
{
	t_pile		*tmp;
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

void	b_to_a(t_pile **a, t_pile **b, size_t size)
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

int	look_for_number(char **numbers)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (numbers[y])
	{
		x = 0;
		while (numbers[y][x])
		{
			if (!ft_isdigit(numbers[y][x]))
				return (0);
			else
				x++;
		}
		y++;
	}
	return (1);
}

void	verif(t_data *data, int ac, char ***av)
{
	if (ac < 2)
		exit(0);
	data->i = 1;
	data->numbers = ft_split((*av)[1], ' ');
	if (ac == 2)
	{
		(*av) = data->numbers;
		data->i--;
	}
}

int	main(int ac, char **av)
{
	t_piles		t_piles;
	t_data		data;

	t_piles.a = NULL;
	t_piles.b = NULL;
	verif(&data, ac, &av);
	while (av[data.i])
	{
		make_node_last(&t_piles.a, ft_atoi(av[data.i++]));
	}
	data.item = t_pile_set_index(&t_piles.a);
	if (data.item <= 5)
		small_algo(&t_piles, data.item);
	else if (data.item < 100)
		make_bucket(&t_piles.a, &t_piles.b, 1, data.item);
	else if (data.item < 300)
		make_bucket(&t_piles.a, &t_piles.b, data.item / 11, data.item);
	else
		make_bucket(&t_piles.a, &t_piles.b, data.item / 16, data.item);
	b_to_a(&t_piles.a, &t_piles.b, data.item);
	free_node(t_piles.a, t_piles.b);
	return (0);
}
