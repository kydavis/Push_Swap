/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:25:17 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/02 15:20:57 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ps_max(int front, int middle, int end)
{
	if (front > middle && front > end)
		return (front);
	else if (middle > end)
		return (middle);
	return (end);
}

unsigned int	ps_min(unsigned int n1, unsigned int n2)
{
	return (n1 < n2 ? n1 : n2);
}
