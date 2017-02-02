/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottomup_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:19:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/30 16:28:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	merge(t_stacks *stack, int width, int direction, int *count)
{
	t_vec	*a;
	t_vec	*b;
	int		cv[2];
	int		ops;
	int		cd;

	a = ((direction & 1) ? &stack->b : &stack->a);
	b = ((direction & 1) ? &stack->a : &stack->b);
	cd = ((direction & 1) ? -1 : 1);
	ops = 2 * width;
	while (ops > 0)
	{
		cv[0] = (!((int*)a->arr)[0] ?
				((int*)a->arr)[a->len - 1] * cd : ((int*)a->arr)[a->len - 1]);
		cv[1] = (!((int*)a->arr)[0] ?
				((int*)a->arr)[0] : ((int*)a->arr)[0] * cd);
		if (cv[0] > cv[1])
		{
			ps_rra(a, b);
			ft_putendl((direction & 1) ? "rrb" : "rra");
			(*count)++;
		}
		ps_pb(a, b);
		ft_putendl((direction & 1) ? "pb" : "pa");
		if (a->len == 1)
		{
			ps_pb(a, b);
			ft_putendl((direction & 1) ? "pb" : "pa");
			(*count)++;
		}
		(*count)++;
		print_stack(stack);
		ops--;
	}
}

/*
** bottom_merge_sort applies a bottom up merge sort algorithm to the stacks.
*/

void	bottom_merge_sort(t_commands *clst, t_stacks *stack)
{
	int	width;
	int	runs;
	int	direction;
	int	opcount;

	width = 1;
	direction = 0;
	opcount = 0;
	while (width < (int)stack->a.total)
	{
		runs = (int)stack->a.total /  (2 * width);
		while (runs > 0)
		{
			ft_printf("stack->a.size:%d runs left:%d\n", stack->a.size, runs);
			merge(stack, width, direction, &opcount);
			runs--;
		}
		direction++;
		width += width;
	}
	print_stack(stack);
	ft_printf("op count:%d\n", opcount);
	(void)clst;
}
