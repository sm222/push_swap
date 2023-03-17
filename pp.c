/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:22:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/17 12:36:57 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pp(t_pile **src, t_pile **dst, char *cmd)
{
	t_pile	*tmp_src;
	t_pile	*tmp_dst;

	if (src && *src)
	{
		tmp_src = (*src)->next;
		tmp_dst = (*dst);
		(*dst) = (*src);
		(*dst)->next = tmp_dst;
		(*src) = tmp_src;
		ft_putendl_fd(cmd, 1);
	}
}
