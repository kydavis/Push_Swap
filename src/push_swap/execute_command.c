/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:39 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/09 16:51:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	shift_min_max(t_stackinfo *si, t_stacks *stack, int command)
{
	if (command == SA || command == SS)
	{
		if (si->max_ai == A.len - 1 || si->max_ai == A.len - 2)
			si->max_ai += (si->max_ai == A.len - 1 ? -1 : 1);
		if (si->min_ai == A.len - 1 || si->min_ai == A.len - 2)
			si->min_ai += (si->min_ai == A.len - 1 ? -1 : 1);
	}
	else if (command == PA && ((int*)A.arr)[A.len - 1] > si->max_a)
	{
		si->max_a = ((int*)A.arr)[A.len - 1];
		si->max_ai = A.len - 1;
	}
	else if (command == PA && ((int*)A.arr)[A.len - 1] < si->min_a)
	{
		si->min_a = ((int*)A.arr)[A.len - 1];
		si->min_ai = A.len - 1;
	}
	if (command == RA || command == RR)
		si->max_ai = (si->max_ai == A.len - 1 ? 0 : si->max_ai + 1);
	if (command == RA || command == RR)
		si->min_ai = (si->min_ai == A.len - 1 ? 0 : si->min_ai + 1);
	if (command == RRA || command == RRR)
		si->max_ai = (si->max_ai == 0 ? A.len : si->max_ai) - 1;
	if (command == RRA || command == RRR)
		si->min_ai = (si->min_ai == 0 ? A.len : si->min_ai) - 1;
}

void	execute_command(t_cmdlst *clst, t_stacks *stack,
		t_stackinfo *si, int command)
{
	clst->cmd[command].swap(&A, &B);
	ft_putendl(clst->cmd[command].name);
	shift_min_max(si, stack, command);
	clst->count++;
}
