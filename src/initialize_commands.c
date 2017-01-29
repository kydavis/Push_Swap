/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:37:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/27 13:35:18 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** initalize_commands takes a command list and assigns a name for the command
** along with a corresponding function pointer
*/

void	initialize_commands(t_commands *list)
{
	ft_strncpy(list[0].name, "sa", sizeof(list[0].name));
	ft_strncpy(list[1].name, "sb", sizeof(list[1].name));
	ft_strncpy(list[2].name, "ss", sizeof(list[2].name));
	ft_strncpy(list[3].name, "pa", sizeof(list[3].name));
	ft_strncpy(list[4].name, "pb", sizeof(list[4].name));
	ft_strncpy(list[5].name, "ra", sizeof(list[5].name));
	ft_strncpy(list[6].name, "rb", sizeof(list[6].name));
	ft_strncpy(list[7].name, "rr", sizeof(list[7].name));
	ft_strncpy(list[8].name, "rra", sizeof(list[8].name));
	ft_strncpy(list[9].name, "rrb", sizeof(list[9].name));
	ft_strncpy(list[10].name, "rrr", sizeof(list[10].name));
	list[0].swap = ps_sa;
	list[1].swap = ps_sb;
	list[2].swap = ps_ss;
	list[3].swap = ps_pa;
	list[4].swap = ps_pb;
	list[5].swap = ps_ra;
	list[6].swap = ps_rb;
	list[7].swap = ps_rr;
	list[8].swap = ps_rra;
	list[9].swap = ps_rrb;
	list[10].swap = ps_rrr;
}
