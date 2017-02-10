/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:43:46 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/06 18:07:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static void	ps_swap_function(t_stacks *stack, t_cmdlst *clst, int pivot)
{
	int	swap;

	swap = (B.len > 1 && ((int*)B.arr)[B.len - 2] > ((int*)B.arr)[B.len - 1]
			? 1 : 0);
	swap += (A.len > 1 && ((int*)A.arr)[A.len - 2] < ((int*)A.arr)[A.len - 1]
			? 2 : 0);
	if (B.len > 1 &&
			((int*)B.arr)[B.len - 1] == 0 && ((int*)B.arr)[B.len - 2] == pivot)
		swap--;
	if (A.len > 1 && ((int*)A.arr)[A.len - 2] == pivot + 1 &&
		((int*)A.arr)[A.len - 1] == (int)(A.total - 1))
			swap -= 2;
	if (swap == 3)
		execute_command(clst, stack, SS);
	else if (swap)
		execute_command(clst, stack, (swap == 1 ? SB : SA));
}

static void	ps_quick_loop(t_stacks *stack, t_cmdlst *clst, int limit, int pivot)
{
/*	int	sorted[2];*/
	int	rots;

/*	ft_printf("\nquick_loop: limit:%d, pivot:%d\n", limit, pivot);*/
	rots = 0;
	if (limit / 2 > 1)
		while (B.len != (size_t)(limit / 2 + 1))
		{
			if (((int*)A.arr)[A.len - 1] <= pivot)
				execute_command(clst, stack, PB);
			else
			{
				execute_command(clst, stack, RA);
				rots++;
			}
			ps_swap_function(stack, clst, pivot);
//		print_stack(stack);///
		}
	else
		ps_swap_function(stack, clst, pivot);
/*	sorted[1] = check_stack(&B, 0, B.len - 1, 1);
	while (!(sorted[0] = check_stack(&A, 0, A.len - 1, 0)) || !sorted[1])
	{
		ft_printf("sorted[0]:%d sorted[1]:%d\n", sorted[0], sorted[1]);
		if (sorted[0] == FALSE && sorted[1] == FALSE)
			execute_command(clst, stack, RR);
		else
			execute_command(clst, stack, (sorted[0] == FALSE ? RA : RB));
//		print_stack(stack);///
		ps_swap_function(stack, clst, pivot);
//		print_stack(stack);///
		sorted[1] = check_stack(&B, 0, B.len - 1, 1);
	}*/
	while (rots-- > 0)
		execute_command(clst, stack, RRA);
	while (B.len > 0)
		execute_command(clst, stack, PA);
}

/*
** GOTTTAAAAQ MIRRRRORRRR
*/

static int	ps_partition(t_stacks *stack, t_cmdlst *clst, int topi, int bottomi)
{
	size_t	pi;
	int		pivot;
	int		direction;
	int		top;
	int		bottom;

	top = (int)A.total - 1 - topi;
	bottom = (int)A.total - 1 - bottomi;
	pivot = top + (bottom - top) / 2;
	if (check_stack(&A, bottomi, topi, 0) == TRUE)
		return (pivot);
	direction = (topi >= (int)A.total / 2 ? 1 : 0);
	pi = (direction ? (int)A.total - topi - 1 : topi + 1);
/*	ft_printf("topi in:%d value:%d, bottomi i:%d value:%d, direction:%d, pi:%d\n",
			topi, ((int*)A.arr)[topi], bottomi, ((int*)A.arr)[bottomi], direction, pi);*/
	while (pi-- > 0)
		execute_command(clst, stack, (direction ? RA : RRA));
	ps_quick_loop(stack, clst, topi - bottomi, pivot);
	pi = (direction ? (int)A.total - topi - 1 : topi + 1);
	while (pi-- > 0)
		execute_command(clst, stack, (direction ? RRA : RA));
	return (pivot);
}

void	quick(t_stacks *stack, t_cmdlst *clst, int topi, int bottomi)
{
	int	pivoti;

/*	ft_printf("topi:%d, bottomi:%d\n", topi, bottomi);*/
	if (topi <= bottomi)
		return ;
	pivoti = (int)A.total - 1 - ps_partition(stack, clst, topi, bottomi);
/*	ft_printf("topi:%d, bottomi:%d pivoti:%d pivot:%d\n",
			topi, bottomi, pivoti, ((int*)A.arr)[pivoti]);
	print_stack(stack);*/
	quick(stack, clst, topi, pivoti + 1);
/*	ft_printf("going for second quick\n");*/
	quick(stack, clst, pivoti - 1, bottomi);
}
