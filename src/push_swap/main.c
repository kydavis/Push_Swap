/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:10:57 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/01 16:17:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

/*
** normalize_stack goes through the array and changes the values in the stack
** to correspond with their relative order to each other.
*/

static void	normalize_stack(t_stacks *raw, t_stacks *working)
{
	size_t	i;
	size_t	j;
	size_t	limit;

	limit = raw->a.len - 1;
	i = 0;
	while (i <= limit)
	{
		j = 0;
		while (j <= limit)
		{
			if (((int*)raw->a.arr)[i] > ((int*)raw->a.arr)[j])
				((int*)working->a.arr)[i] += 1;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cmdlst	clst;
	t_stacks	raw_stack;
	t_stacks	working_stack;

	ft_bzero((void*)&raw_stack, sizeof(raw_stack));
	ft_bzero((void*)&working_stack, sizeof(working_stack));
	initialize_commands(clst.cmd);
	clst.count = 0;
	if (argc < 2 || !(load_data(&raw_stack, argc - 1, argv + 1)) ||
			!(load_data(&working_stack, argc - 1, NULL)))
	{
		ft_putendl_fd("Error", 2);
		return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
	}
	normalize_stack(&raw_stack, &working_stack);
	sort(&working_stack, &clst);
	print_stack(&working_stack);
	return (0);
}
