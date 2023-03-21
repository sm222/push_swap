/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:08:38 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/21 13:54:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
{
	size_t	i;
	int		flp;
	long	val;

	if (!s)
		return (0);
	val = 0;
	flp = 1;
	i = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			flp *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		val = val * 10 + (s[i++] - '0');
	return (val * flp);
}
