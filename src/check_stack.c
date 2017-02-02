/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:17:06 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/30 11:18:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** check_stack will check to make sure that stack a has been sorted after
** it went through all of the instructions.
*/

int	check_stack(t_vec *a)
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


