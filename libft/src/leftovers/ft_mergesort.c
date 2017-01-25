/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:06:25 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/14 17:40:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*ft_dealloc(int *a1. int *a2)
{
	ft_memdel((void*)&a1);
	ft_memdel((void*)&a2);
	return (NULL);
}


int	*ft_mergesort_i(int *array, size_t n)
{
	int		*result;
	int		*sub1;
	int		*sub2;
	size_t	i;

	if (!(result = (int*)ft_memalloc(sizeof(result) * n)))
		return (NULL);
	sub1 = NULL;
	sub2 = NULL;
	if (n > 1)
	{
		if (!(sub1 = ft_mergesort_i(array, n / 2)))
			return (ft_deaolloc(result, NULL));
		if (!(sub2 = ft_mergesort_i(array + n / 2, (n / 2) + (n % 2 ? 0 : 1))))
			return (ft_dealloc(result, sub1));
	}
	i = 0;
	while (i < n)
	{
	}
	ft_dealloc(sub1, sub2);
	return (result);
}
