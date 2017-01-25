/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:30:01 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/25 12:21:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <ft_vector.h>

typedef			s_commands
{
	const char	cmd[3];
	void		(*swap)(t_i32vec *, t_i32vec *);
}				t_commands

int ch_cleanup(int erno, void **a1, void **a2, void **a3)
#endif
