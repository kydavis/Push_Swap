/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:06:15 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/30 18:34:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	operate_one_stack(t_cmdlst *clst, t_stacks *stack, int dir)
{
	int	min_max;

	min_max = (dir ? ps_min(((int*)A.arr)[0], ((int*)A.arr)[A.len - 1],
				((int*)A.arr)[A.len - 2]) : ps_max(((int*)B.arr)[0],
				((int*)B.arr)[B.len - 1], ((int*)B.arr)[B.len - 2]));
	if (dir)
	{
		if (((int*)A.arr)[0] == min_max && A.len > 2)
			execute_command(clst, stack, RRA);
		else if (((int*)A.arr)[A.len - 2] == min_max && A.len > 1)
			execute_command(clst, stack, SA);
	}
	else
	{
		if (((int*)B.arr)[0] == min_max && B.len > 2)
			execute_command(clst, stack, RRB);
		else if (((int*)B.arr)[B.len - 2] == min_max && B.len > 1)
			execute_command(clst, stack, SB);
	}
	execute_command(clst, stack, (dir ? PB : PA));
	if (dir && B.len == 2)
		execute_command(clst, stack,
				(((int*)B.arr)[0] < ((int*)B.arr)[1] ? NOP : SB));
	else if (!dir && A.len == 2)
		execute_command(clst, stack,
				(((int*)A.arr)[0] > ((int*)A.arr)[1] ? NOP : SA));
}

/*static void	operate_one_stack(t_cmdlst *clst, t_stacks *stack, int dir)
{
	if (dir)
	{
		if (((int*)A.arr)[0] < ((int*)A.arr)[A.len - 1] && A.len > 2 &&
				((int*)A.arr)[0] < ((int*)A.arr)[A.len - 2])
			execute_command(clst, stack, RRA);
		else if (A.len > 1 &&
				((int*)A.arr)[A.len - 2] < ((int*)A.arr)[A.len - 1])
			execute_command(clst, stack, SA);
	}
	else
	{
		if (((int*)B.arr)[0] > ((int*)B.arr)[B.len - 1] && B.len > 2 &&
				((int*)B.arr)[0] > ((int*)B.arr)[B.len - 2])
			execute_command(clst, stack, RRB);
		else if (B.len > 1 &&
				((int*)B.arr)[B.len - 2] > ((int*)B.arr)[B.len - 1])
			execute_command(clst, stack, SB);
	}
	execute_command(clst, stack, (dir == 1 ? PB : PA));
	if (dir && B.len == 2)
		execute_command(clst, stack,
				(((int*)B.arr)[0] < ((int*)B.arr)[1] ? NOP : SB));
	else if (!dir && A.len == 2)
		execute_command(clst, stack,
				(((int*)A.arr)[0] > ((int*)A.arr)[1] ? NOP : SA));
}*/

/*static void	operate_both_stacks(t_commands *clst, t_stacks *stack, int dir)
{
	execute_command(clst, stack, (dir == 1 ? PB : PA));
}*/

static void	move_stack(t_cmdlst *clst, t_stacks *stack, int dir)
{
	size_t	i;

	i = 0;
	while (i < A.total)
	{
/*		if ((dir == 1 ? B.len : A.len) >= 2)
			operate_both_stacks(clst, stack, dir);
		else*/
			operate_one_stack(clst, stack, dir);
		i++;
	}
}

/*
** acomp/bcomp[0] = value at the bottom of the perspective stack
** acomp/bcomp[1] = value at the top of the perspective stack
** acomp/bcomp[2] = value second to the top of the perspective stack
*/

#include <unistd.h>
void	sort(t_stacks *stack, t_cmdlst *clst)
{
	char c;

	while (!(check_stack(&A)))
	{
		move_stack(clst, stack, 1);
		print_stack(stack);
		ft_printf("Number of instructions:%d\n", clst->count);
		while (!(read(0, &c, 1)))
			;
		move_stack(clst, stack, 0);
		print_stack(stack);
		ft_printf("Number of instructions:%d\n", clst->count);
		while (!(read(0, &c, 1)))
			;
	}
}
