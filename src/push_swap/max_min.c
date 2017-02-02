/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:25:17 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/30 14:29:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ps_max(int front, int middle, int end)
{
	if (front > middle && front > end)
		return (front);
	else if (middle > end)
		return (middle);
	return (end);
}

int	ps_min(int front, int middle, int end)
{
	if (front < middle && front < end)
		return (front);
	else if (middle < end)
		return (middle);
	return (end);
}
