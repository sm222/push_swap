/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/24 14:16:22 by anboisve         ###   ########.fr       */
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

char	***verif(t_data *data, int ac, char **av)
{
	char	***holder;
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	holder = NULL;
	if (ac == 1)
		exit(0);
	data->i = 1;
	holder = ft_calloc(ft_double_strlen(av) + 1, sizeof(char **));
	while (i < ft_double_strlen(av) + 1)
	{
		holder[j++] = ft_split(av[i], ' ');
		i++;
	}
	i = 0;
	while (holder[i])
		if (while_number(holder[i++]) == 0)
			free_arr(holder, 2);
	return (holder);
}

void	start_data(t_piles *piles, char ***number)
{
	size_t	i;
	size_t	j;
	size_t	item;

	i = 0;
	item = 0;
	while (number[i])
	{
		j = 0;
		while (number[i][j])
		{
			if (ft_atol(number[i][j]) > INT_MAX || ft_atol(number[i][j]) \
			< INT_MIN || ft_strlen(number[i][j]) > 11)
				free_arr(number, 2);
			make_node_last(&piles->a, ft_atoi(number[i][j++]));
			item++;
			if (node_len(piles->a) != item)
			{
				free_node(piles->a, NULL);
				free_arr(number, 2);
			}
		}
		i++;
	}
	free_arr(number, 0);
}

int	main(int ac, char **av)
{
	t_piles		piles;
	t_data		data;

	piles.a = NULL;
	piles.b = NULL;
	data.numbers = verif(&data, ac, av);
	start_data(&piles, data.numbers);
	if (look_double(&piles.a) == 0)
	{
		free_node(piles.a, piles.b);
		exit(ft_putendl_fd("Error", 2));
	}
	data.item = t_pile_set_index(&piles.a);
	if (data.item <= 11)
		small_algo(&piles, data.item);
	else if (data.item < 100)
		make_bucket(&piles.a, &piles.b, 1, data.item);
	else if (data.item < 300)
		make_bucket(&piles.a, &piles.b, data.item / 7, data.item);
	else
		make_bucket(&piles.a, &piles.b, data.item / 15, data.item);
	b_to_a(&piles.a, &piles.b, data.item);
	free_node(piles.a, piles.b);
	return (0);
}
