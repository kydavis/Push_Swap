/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:10:57 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/15 22:22:38 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	main(int argc, char **argv)
{
	t_cmdlst	clst;
	t_stacks	raw_stack;
	size_t		i;
	int			min_count;
	int			min_i;

	ft_bzero((void*)&raw_stack, sizeof(raw_stack));
	initialize_commands(clst.cmd);
	clst.print = 0;
	i = 4;
	if (argc < 2 || !(load_data(&raw_stack, argc - 1, argv + 1)))
		return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
	if ((check_stack(&raw_stack.a, 0, raw_stack.a.len - 1, 0)))
		return (cleanup(0, &raw_stack.a, &raw_stack.b, NULL));
	min_count = FT_S32_MAX;
	min_i = 4;
	while (i < raw_stack.a.total / 2)
	{
		clst.count = 0;
		if (!(load_data(&raw_stack, argc - 1, argv + 1)))
			return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
		insertion(&raw_stack, &clst, i);
		cleanup(0, &raw_stack.a, &raw_stack.b, NULL);
		if (clst.count < min_count)
		{
			min_count = clst.count;
			min_i = i;
		}
/*		ft_printf("i:%d, Number of commands:%d\n", i, clst.count);*/
		i *= 2;
	}
	if (!(load_data(&raw_stack, argc - 1, argv + 1)))
		return (cleanup(-1, &raw_stack.a, &raw_stack.b, NULL));
	clst.print = 1;
	clst.count = 0;
	insertion(&raw_stack, &clst, min_i);
/*	ft_printf("i:%d, Number of commands:%d\n", min_i, clst.count);*/
/*	print_stack(&raw_stack);*/
	return (cleanup(0, &raw_stack.a, &raw_stack.b, NULL));
}
