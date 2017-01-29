/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:15:19 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/27 14:56:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** pa and pb can probably be combined
*/

void	ps_p(t_vec *va, t_vec *vb)
{
	int	*a;
	int	*b;

	a = (int*)va->arr;
	b = (int*)vb->arr;
	a[va->len] = b[vb->len - 1];
/*	((int*)a->arr)[a->len - 1] = ((int*)b->arr)[b->len];*/
	va->len++;
	vb->len--;
}

/*
** pushes the top value of b onto a.
*/

void	ps_pa(t_vec *a, t_vec *b)
{
	ps_p(a, b);
}

/*
** pushes the top value of a onto b.
*/

void	ps_pb(t_vec *a, t_vec *b)
{
	ps_p(b, a);
}

