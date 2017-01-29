/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:17:11 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/28 19:05:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

/*
** The following functions are used for reading the commands given, and applying
** the commands to the stacks for both a and b. Will return 0 if there is an
** invalid instruction given.
*/

static int	command_dispatcher(t_stacks *stack, t_commands *clst, char *cmd)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!(ft_strcmp(clst[i].name, cmd)))
		{
			clst[i].swap(&stack->a, &stack->b);
			return (1);
		}
		i++;
	}
	return (0);
}

int			process_instructions(t_stacks *stack, t_commands *clst)
{
	char	*command;
	int		erno;

	while ((erno = get_next_line(0, &command)))
	{
		if (erno == -1)
			return (0);
		if (!(command_dispatcher(stack, clst, command)))
			return (0);
		ft_printf("\ncommand:%s\n", command);
		print_stack(stack);///
		ft_memdel((void*)&command);
	}
	return (1);
}
