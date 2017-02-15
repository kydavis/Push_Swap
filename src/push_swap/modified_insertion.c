/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_insertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:48:41 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 00:27:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** Idea behind modified insetion sort.
** Calculate what value in index A and insertion position in B
** would require the least number of steps to access.
**
** Sample:	min		max	
**			mid		min
**			max		mid
**			__		__
**			A		A
**
**	if new_value > max || new_value < min
**		insert between max and min.
**	else if (new_value > mid && new_value < max)
**		insert between mid and max.
**	else if (new_value > min && new_value < mid)
**		insert between min and mid.
*/


static int	calculate_rotations(t_rotcnt *cnt, size_t ai, size_t bi,
		t_stacks *stack)
{
	cnt->ra = A.len - 1 - ai;
	cnt->rb = B.len - 1 - bi;
	cnt->rr = (cnt->ra < cnt->rb ? cnt->ra : cnt->rb);
	cnt->rra = ai + 1;
	cnt->rrb = bi + 1;
	cnt->rrr = (cnt->rra < cnt->rrb ? cnt->rra : cnt->rrb);
	cnt->ttl_rot = ps_min(cnt->ra + cnt->rrb, cnt->rb + cnt->rra,
			cnt->ra + cnt->rb - cnt->rr);
	if (cnt->ttl_rot > cnt->rra + cnt->rrb - cnt->rrr)
		cnt->ttl_rot = cnt->rra + cnt->rrb - cnt->rrr;
	cnt->rr = (cnt->ttl_rot != cnt->ra + cnt->rb - cnt->rr ? -1 : cnt->rr);
	cnt->rrr = (cnt->ttl_rot != cnt->rra + cnt->rrb - cnt->rrr ? -1 : cnt->rrr);
	cnt->ra = ((cnt->ttl_rot != cnt->ra + cnt->rrb && cnt->rr == -1) ||
			cnt->rrr != -1 ? 0 : cnt->ra);
	cnt->rb = ((cnt->ttl_rot != cnt->rb + cnt->rra && cnt->rr == -1) ||
			cnt->rrr != -1 ? 0 : cnt->rb);
	cnt->rrb = ((cnt->ttl_rot != cnt->ra + cnt->rrb && cnt->rrr == -1) ||
			cnt->rb != 0 ? 0 : cnt->rrb);
	cnt->rra = ((cnt->ttl_rot != cnt->rb + cnt->rra && cnt->rrr == -1) ||
			cnt->ra != 0 ? 0 : cnt->rra);
	cnt->ra -= (cnt->rr == -1 ? 0 : cnt->rr);
	cnt->rb -= (cnt->rr == -1 ? 0 : cnt->rr);
	cnt->rra -= (cnt->rrr == -1 ? 0 : cnt->rrr);
	cnt->rrb -= (cnt->rrr == -1 ? 0 : cnt->rrr);
	return (cnt->ttl_rot);
}

static int	rotation_count(t_stacks *stack, t_stackinfo *si, t_rotcnt *cnt,
		size_t insert_index)
{
	size_t			i;
	int				insert_value;
	int				rot_count;

	insert_value = ((int*)B.arr)[insert_index];
	if (insert_value > si->max_a || insert_value < si->min_a)
		i = (si->max_ai == 0 ? A.len : si->max_ai) - 1;
	else
	{
		i = A.len - 1;
		if (!(insert_value < ((int*)A.arr)[i] &&
			insert_value > ((int*)A.arr)[0]))
		{
			i--;
			while (!(insert_value > ((int*)A.arr)[i + 1] &&
						insert_value < ((int*)A.arr)[i]))
				i--;
		}
	}
/*		ft_printf("insert:%d index:%d insert_position:%i\n", insert_value,
				insert_index, i);*/
	rot_count = calculate_rotations(cnt, i, insert_index, stack);
	return (rot_count);
}

/*
** find_insertions chooses the value in stack A that would cost the least
** number of operations to insert.
*/

static int		find_insertion(t_stacks *stack, t_stackinfo *si, t_rotcnt *cnt)
{
	t_rotcnt	trot;
	long long	i;
	int			ttl_rotations;
	int			temp_count;

	i = B.len - 1;
	ttl_rotations = A.total;
	ft_bzero((void*)&trot, sizeof(trot));
	while (i >= 0)
	{
		temp_count = rotation_count(stack, si, &trot, i);
		if (temp_count < ttl_rotations)
		{
/*		ft_printf("tra:%d, trb:%d, trr:%d. trra:%d, trrb:%d, trrr:%d, ttrot:%d, trot:%d\n",
				trot.ra, trot.rb, trot.rr, trot.rra, trot.rrb, trot.rrr, ttl_rotations, temp_count);*/
			ttl_rotations = temp_count;
			ft_memmove((void*)cnt, (void*)&trot, sizeof(trot));
		}
		i--;
	}
	return (temp_count);
}

static void	sort_three_a(t_stacks *stack, t_stackinfo *si, t_cmdlst *clst)
{
	size_t	i;

	si->max_a = ps_max(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	si->min_a = ps_min(((int*)A.arr)[A.len - 3], ((int*)A.arr)[A.len - 2],
			((int*)A.arr)[A.len - 1]);
	i = A.len - 3;
	while (i < A.len)
	{
		if (((int*)A.arr)[i] == si->max_a)
			si->max_ai = i;
		else if (((int*)A.arr)[i] == si->min_a)
			si->min_ai = i;
		i++;
	}
	if ((si->max_ai == 2 && si->min_ai == 0) || si->max_ai == (si->min_ai - 1))
	{
		if (B.len > 1 && ((int*)B.arr)[B.len - 1] > ((int*)B.arr)[B.len - 2])
			execute_command(clst, stack, si, SA);
		else
			execute_command(clst, stack, si, SS);
	}
}

#include <unistd.h>
void	insertion(t_stacks *stack, t_cmdlst *clst)
{
	t_stackinfo	si;
	t_rotcnt	count;

/*	si.flag = flag;*/
	while (A.len > 3)
	{
/*		if (flag == 1 || flag == 4)
			detect_swaps(clst, stack, &si);
		else if (flag == 2 || flag == 5)
			sort_three_a(stack, &si, clst);*/
		execute_command(clst, stack, &si, PB);
	}
	sort_three_a(stack, &si, clst);
/*	ft_printf("max:%d, max_ai:%d, min:%d, min_ai:%d\n", si.max_a, si.max_ai, si.min_a, si.min_ai);*/
	while (A.len < A.total)
	{
		find_insertion(stack, &si, &count);
/*		ft_printf("ra:%d, rb:%d, rr:%d. rra:%d, rrb:%d, rrr:%d\n",
				count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
		if (A.len > 490)
			print_stack(stack);*/
		while (count.ra-- > 0)
			execute_command(clst, stack, &si, RA);
		while (count.rb-- > 0)
			execute_command(clst, stack, &si, RB);
		while (count.rr-- > 0)
			execute_command(clst, stack, &si, RR);
		while (count.rra-- > 0)
			execute_command(clst, stack, &si, RRA);
		while (count.rrb-- > 0)
			execute_command(clst, stack, &si, RRB);
		while (count.rrr-- > 0)
			execute_command(clst, stack, &si, RRR);
		execute_command(clst, stack, &si, PA);
	}
	while (!(check_stack(&A, 0, A.len - 1, 0)))
			execute_command(clst, stack, &si, si.min_ai < A.len / 2 ? RRA : RA);
}
