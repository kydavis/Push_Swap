/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:30:01 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/26 17:18:08 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <push_swap.h>

int	checker(t_stacks *stack, t_commands *clst, int argc, char **argv);
int	process_instructions(t_stacks *stack, t_commands *clst);

#endif
