/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:46:08 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 19:14:31 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>
#include <unistd.h>

char	**load_instructions(void)
{
	t_vec	instructions;
	char	**result;
	ssize_t		ret;
	char	buffer[BUFF_SIZE];

	if (!(ft_initialize_vec(&instructions, 1, BUFF_SIZE, 0)))
		return (NULL);
	result = NULL;
	while ((ret = read(0, buffer, BUFF_SIZE)) > 0)
	{
		if (!(ft_grow_vec(&instructions, instructions.len + ret)))
		{
			ft_memdel(&instructions.arr);
			return (NULL);
		}
		ft_memmove((char*)instructions.arr + instructions.len, buffer, ret);
		instructions.len += BUFF_SIZE;
	}
	if (ret == 0)
		result = ft_strsplit((char*)instructions.arr, '\n');
	ft_memdel(&instructions.arr);
	return (result);
}

int	checker(t_stacks *stack, t_commands *clst, t_cflags *flags)
{
	int		ret;
	char	**commands;

	if (!(load_data(stack, flags->argc, flags->argv)))
		return (-1);
	if (!(commands = load_instructions()))
		return (cleanup(-1, &stack->a, &stack->b, NULL));
	if (!(process_instructions(stack, commands, clst, flags)))
		return (cleanup(-1, &stack->a, &stack->b, commands));
	ret = check_stack(&stack->a, 0, A.total - 1, 0);
	return (cleanup(ret, &stack->a, &stack->b, commands));
}
