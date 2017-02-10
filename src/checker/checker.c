/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:46:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/07 11:09:34 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

int			checker(t_stacks *stack, t_commands *clst, int argc, char **argv)
{
	int		ret;

	if (!(load_data(stack, argc, argv)))
		return (-1);
	if (!(process_instructions(stack, clst)))
		return (cleanup(-1, &stack->a, &stack->b, NULL));
	ret = check_stack(&stack->a, 0, A.total - 1, 0);
	print_stack(stack);///
	return (cleanup(ret, &stack->a, &stack->b, NULL));
}
