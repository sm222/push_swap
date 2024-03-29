/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_double_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/19 16:03:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpy_double_char(char **str)
{
	int		i;
	int		j;
	char	**new;

	j = 0;
	new = NULL;
	if (!str)
		return (NULL);
	i = ft_double_strlen(str);
	new = ft_calloc(i + 1, sizeof(char *));
	while (j < i)
	{
		new[j] = ft_strdup(str[j]);
		j++;
	}
	return (new);
}
