/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:20:26 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/19 17:43:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char ***data, int exit_f)
{
	size_t	i;

	i = 0;
	while (data[i])
		ft_double_sfree((void **)data[i++]);
	free(data);
	if (exit_f)
	{
		if (exit_f == 2)
			ft_putendl_fd("error\n", 2);
		exit(1);
	}
}

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

int	while_number(char **data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (ft_isdigit(data[i][j]))
				j++;
			else if (data[i][j] == '-' && ft_isdigit(data[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

char	***verif(t_data *data, int ac, char **av)
{
	char	***holder;
	size_t	i;

	i = 1;
	holder = NULL;
	if (ac < 3)
		exit(0);
	data->i = 1;
	if (ac >= 2)
	{
		holder = ft_calloc(ft_double_strlen(av), sizeof(char **));
		while (i < ft_double_strlen(av))
		{
			holder[i - 1] = ft_split(av[i], ' ');
			i++;
		}
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

	i = 0;
	while (number[i])
	{
		j = 0;
		while (number[i][j])
		{
			make_node_last(&piles->a, ft_atoi(number[i][j++]));
			if (piles->a == NULL)
				free_arr(number, 2);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_piles		piles;
	t_data		data;
	char		***numbers;

	piles.a = NULL;
	piles.b = NULL;
	numbers = verif(&data, ac, av);
	start_data(&piles, numbers);
	data.item = t_pile_set_index(&piles.a);
	if (data.item <= 10)
		small_algo(&piles, data.item);
	else if (data.item < 100)
		make_bucket(&piles.a, &piles.b, 1, data.item);
	else if (data.item < 300)
		make_bucket(&piles.a, &piles.b, data.item / 7, data.item);
	else
		make_bucket(&piles.a, &piles.b, data.item / 13, data.item);
	b_to_a(&piles.a, &piles.b, data.item);
	free_node(piles.a, piles.b);
	free_arr(numbers, 1);
	return (0);
}
