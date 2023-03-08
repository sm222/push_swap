/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:34:54 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/08 16:02:27 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_ft/libft.h"
# include <limits.h>

typedef struct s_ps
{
	struct s_ps	*head;
	int			data;
	size_t		i;
	struct s_ps	*next;

}	t_ps;

typedef struct s_piles
{
	t_ps	*a;
	t_ps	*b;

}	t_piles;

size_t	node_len(t_ps *node);
void	ss(t_ps *a, t_ps *b);
void	pa(t_ps **a, t_ps **b);
void	pb(t_ps **a, t_ps **b);
void	s_p(t_ps *node);
void	rr(t_ps **a, t_ps **b);
int		r_r(t_ps **p);

#endif 
