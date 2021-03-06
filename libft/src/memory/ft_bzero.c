/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:28:17 by kdavis            #+#    #+#             */
/*   Updated: 2016/11/28 10:02:26 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** Sets n bytes located at C-string s to 0.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
