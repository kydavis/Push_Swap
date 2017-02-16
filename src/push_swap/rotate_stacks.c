/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:04:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 15:31:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Rotate_stacks executes all the rotation commands queded in the rotcnt struct
*/

void	rotate_stacks(t_stacks *stack, t_cmdlst *clst, t_rotcnt *rot,
		t_stackinfo *si)
{
		while (rot->ra-- > 0)
			execute_command(clst, stack, si, RA);
		while (rot->rb-- > 0)
			execute_command(clst, stack, si, RB);
		while (rot->rr-- > 0)
			execute_command(clst, stack, si, RR);
		while (rot->rra-- > 0)
			execute_command(clst, stack, si, RRA);
		while (rot->rrb-- > 0)
			execute_command(clst, stack, si, RRB);
		while (rot->rrr-- > 0)
			execute_command(clst, stack, si, RRR);
}
