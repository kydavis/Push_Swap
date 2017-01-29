/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:46:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/28 19:38:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

/*
** check_stack will check to make sure that stack a has been sorted after
** it went through all of the instructions.
*/

static int	check_stack(t_vec *a)
{
	int	i;
	int	*array;

	i = a->len - 1;
	array = (int*)a->arr;
	while (i >= 1)
	{
		if (array[i] > array[i - 1])
			return (0);
		i -= 1;
	}
	return (1);
}

int			checker(t_stacks *stack, t_commands *clst, int argc, char **argv)
{
	int		ret;

	if (!(load_data(stack, argc, argv)))
		return (-1);
	if (!(process_instructions(stack, clst)))
		return (cleanup(-1, &stack->a, &stack->b, NULL));
	ret = check_stack(&stack->a);
	return (cleanup(ret, &stack->a, &stack->b, NULL));
}
