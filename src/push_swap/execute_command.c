/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:39 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 22:10:54 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	shift_min_max(t_stackinfo *si, t_vec *stack, int command, int sf)
{
	if (command == SA + sf || command == SS)
	{
		if (si->max_i == stack->len - 1 || si->max_i == stack->len - 2)
			si->max_i += (si->max_i == stack->len - 1 ? -1 : 1);
		if (si->min_i == stack->len - 1 || si->min_i == stack->len - 2)
			si->min_i += (si->min_i == stack->len - 1 ? -1 : 1);
	}
	else if (command == PA + sf && ((int*)stack->arr)[stack->len - 1] > si->max)
	{
		si->max = ((int*)stack->arr)[stack->len - 1];
		si->max_i = stack->len - 1;
	}
	else if (command == PA + sf && ((int*)stack->arr)[stack->len - 1] < si->min)
	{
		si->min = ((int*)stack->arr)[stack->len - 1];
		si->min_i = stack->len - 1;
	}
	if (command == RA + sf || command == RR)
		si->max_i = (si->max_i == stack->len - 1 ? 0 : si->max_i + 1);
	if (command == RA + sf || command == RR)
		si->min_i = (si->min_i == stack->len - 1 ? 0 : si->min_i + 1);
	if (command == RRA + sf || command == RRR)
		si->max_i = (si->max_i == 0 ? stack->len : si->max_i) - 1;
	if (command == RRA + sf || command == RRR)
		si->min_i = (si->min_i == 0 ? stack->len : si->min_i) - 1;
}

void	execute_command(t_cmdlst *clst, t_stacks *stack,
		t_stackinfo *si, int command)
{
	clst->cmd[command].swap(&A, &B);
	if (clst->print)
		ft_putendl(clst->cmd[command].name);
	if (si->stflag == 0)
		shift_min_max(si, &A, command, si->stflag);
	else if (si->stflag == 1)
		shift_min_max(si, &B, command, si->stflag);
	clst->count++;
}
