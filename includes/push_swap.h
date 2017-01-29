/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:01:53 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/28 19:34:11 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_vector.h>

typedef	struct	s_commands
{
	void		(*swap)(t_vec *, t_vec *);
	char		name[5];
}				t_commands;

typedef struct	s_stacks
{
	t_vec		a;
	t_vec		b;
}				t_stacks;

int				load_data(t_stacks *stack, int argc, char **argv);
void			print_stack(t_stacks *stack);

/*
** command functions:
*/
void			initialize_commands(t_commands *list);
void			ps_sa(t_vec *a, t_vec *b);
void			ps_sb(t_vec *a, t_vec *b);
void			ps_ss(t_vec *a, t_vec *b);
void			ps_pa(t_vec *a, t_vec *b);
void			ps_pb(t_vec *a, t_vec *b);
void			ps_ra(t_vec *a, t_vec *b);
void			ps_rb(t_vec *a, t_vec *b);
void			ps_rr(t_vec *a, t_vec *b);
void			ps_rra(t_vec *a, t_vec *b);
void			ps_rrb(t_vec *a, t_vec *b);
void			ps_rrr(t_vec *a, t_vec *b);

/*
** cleanup functions:
*/
int				cleanup(int ret, t_vec *a, t_vec *b, char **argv);

#endif
