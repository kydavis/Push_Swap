/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:16:20 by kdavis            #+#    #+#             */
/*   Updated: 2017/01/25 12:20:04 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <string.h>

typedef struct	s_i8vec
{
	char		*vec;
	size_t		len;
	size_t		size;
}				t_i8vec;

typedef struct	s_i32vec
{
	int			*vec;
	size_t		len;
	size_t		size;
}				t_i32vec;

typedef struct	s_i64vec
{
	long long	*vec;
	size_t		len;
	size_t		size;
}				t_i64vec;

#endif
