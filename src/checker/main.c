/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:29:23 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/16 15:34:47 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft.h>

int	main(int argc, char **argv)
{
	t_commands	cmd[11];
	t_stacks	stack;
	int			ret;

	if (argc < 2)
		return (0);
	ret = 0;
	ft_bzero((void*)&stack, sizeof(stack));
	initialize_commands(cmd);
	if ((ret = checker(&stack, cmd, argc - 1, argv + 1)) == -1)
		ft_putendl_fd("Error", 2);
	else if (ret == 0)
		ft_putendl("KO");
	else if (ret == 1)
		ft_putendl("OK");
	return (0);
}
