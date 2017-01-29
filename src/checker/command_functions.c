/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:42:33 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/26 11:29:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Look into combining some of these functions into one function?
** mostly depends on structure of how I call the functions.
*/

/*
** ps_s is the body function for swapping the top two values..
*/

void	ps_s(t_vec *a)
{
	int	*top;

	if (a->len < 2)
		return ;
	top = (int*)a->arr + a->len - 1;
	ft_xorswapi(top, top - 1);
}

/*
**  Swaps the top two values of stack a
*/

void	ps_sa(t_vec *a, t_vec *b)
{
	(void)b;
	ps_s(a);
}

/*
**  Swaps the top two values of stack b
*/

void	ps_sb(t_vec *a, t_vec *b)
{
	(void)a;
	ps_s(b);
}

/*
** Swaps the top two values of stack a and b
*/

void	ps_ss(t_vec *a, t_vec *b)
{
	ps_s(a);
	ps_s(b);
}

/*
** pa and pb can probably be combined
*/

void	ps_p(t_vec *a, t_vec *b)
{
	(int*)a->arr + a->len = (int*)b->arr + b->len;
	a->len++;
	b->len--;
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

/*
** Main body for the shift up function
*/

void	ps_r(t_vec *a)
{
	long	*m2src;
	long	*m2dst;
	int		lindex;
	int		size;
	int		tmp;

	size = a->len - 1;
	m2src = (long*)a->arr;
	m2dst = (long*)(a->arr + 1);
	tmp = *(a->arr + size);
	lindex = size / 2;
	if (size % 2)
		(int*)a->arr[size] = (int*)a->arr[size - 1];
	while (lindex-- > 0)
		m2dst[lindex] = m2src[lindex];
	*a->arr = tmp;
}

void	ps_ra(t_vec *a, t_vec *b)
{
	(void)b;
	ps_r(a);
}

void	ps_rb(t_vec *a, t_vec *b)
{
	(void)a;
	ps_r(b);
}

void	ps_rr(t_vec *a, t_vec *b)
{
	ps_r(a);
	ps_r(b);
}

/*
** Main body for shift down function.
*/

void	ps_dr(t_vec *a)
{
	long	*m2src;
	long	*m2dst;
	int		lindex;
	int		size;
	int		tmp;

	size = a->len - 1;
	m2src = (long*)(a->arr + 2);
	m2dst = (long*)(a->arr + 1);
	tmp = *a->arr;
	lindex = size / 2;
	if (size % 2)
		(int*)*a->arr = (int*)*(a->arr + 1);
	while (lindex-- > 0)
		*m2dst++ = *m2src++;
	(int*)a->arr[size] = tmp;
}

void	ps_rra(t_vec *a, t_vec *b)
{
	(void)b;
	ps_dr(a);
}
void	ps_rrb(t_vec *a, t_vec *b)
{
	(void)a;
	ps_dr(b);
}
void	ps_rrr(t_vec *a, t_vec *b)
{
	ps_dr(a);
	ps_dr(b);
}
