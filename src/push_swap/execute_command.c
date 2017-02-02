/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:39 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/30 16:26:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	execute_command(t_cmdlst *clst, t_stacks *stack, int command)
{
	if (command == NOP)
		return ;
	clst->cmd[command].swap(&A, &B);
	ft_putendl(clst->cmd[command].name);
	clst->count++;
}
