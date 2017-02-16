/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_insertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:48:41 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 22:24:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** sort_three will sort stack a and assign the max and min values to the stack.
*/

static void	sort_three(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
{
	size_t	i;

	si->max = ps_max(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	si->min = ps_min(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	i = A.len - 3;
	while (i < A.len)
	{
		if (((int*)A.arr)[i] == si->max)
			si->max_i = i;
		else if (((int*)A.arr)[i] == si->min)
			si->min_i = i;
		i++;
	}
	if ((si->max_i == 2 && si->min_i == 0) || si->max_i == (si->min_i - 1))
	{
		if (B.len > 1 && ((int*)B.arr)[B.len - 1] > ((int*)B.arr)[B.len - 2])
			execute_command(clst, stack, si, SA);
		else
			execute_command(clst, stack, si, SS);
	}
}

static void	initialize_b(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
{
	si->stflag = -1;
	execute_command(clst, stack, si, PB);
	execute_command(clst, stack, si, PB);
	if (((int*)B.arr)[0] > ((int*)B.arr)[1])
	{
		si->max_i = 0;
		si->min_i = 1;
	}
	else
	{
		si->max_i = 1;
		si->min_i = 0;
	}
	si->max = ((int*)B.arr)[si->max_i];
	si->min = ((int*)B.arr)[si->min_i];
	si->stflag = 1;
}

void	insertion(t_stacks *stack, t_cmdlst *clst, size_t push_over)
{
	t_stackinfo	si;
	t_rotcnt	count;

	if (A.len > 4)
		initialize_b(stack, &si, clst);
	while (A.len > 3)
	{
/*	ft_printf("max:%d, max_i:%d, min:%d, min_i:%d\n", si.max, si.max_i, si.min, si.min_i);
	print_stack(stack);*/
		if (A.len > push_over)
		{
			choose_insertion(stack, &si, &count);
			rotate_stacks(stack, clst, &count, &si);
		}
		execute_command(clst, stack, &si, PB);
	}
	si.stflag = 0;
	if (A.len > 2)
		sort_three(stack, &si, clst);
/*	ft_printf("max:%d, max_i:%d, min:%d, min_i:%d\n", si.max, si.max_i, si.min, si.min_i);
	print_stack(stack);*/
	while (A.len < A.total)
	{
		choose_insertion(stack, &si, &count);
/*		ft_printf("ra:%d, rb:%d, rr:%d. rra:%d, rrb:%d, rrr:%d\n",
				count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
		if (A.len > 490)*/
		rotate_stacks(stack, clst, &count, &si);
		execute_command(clst, stack, &si, PA);
/*		ft_printf("max:%d, max_i:%d, min:%d, min_i:%d\n", si.max, si.max_i, si.min, si.min_i);
		print_stack(stack);*/
	}
	while (!(check_stack(&A, 0, A.len - 1, 0)))
			execute_command(clst, stack, &si, si.min_i < A.len / 2 ? RRA : RA);
}
