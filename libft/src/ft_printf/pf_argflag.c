/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_argflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 07:07:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/12/09 08:16:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
** NEEDS WORKING ON!!!!
*/

/*
** argdata retrieves the data from the appropriate argument
*/

t_vdata		pf_argdata(t_pfflg *fl, va_list ap)
{
	t_vdata	data;
	va_list	as;
	int		ac;

	ac = 1;
	va_copy(as, ap);
	while (ac++ < fl->argf)
		va_arg(as, int);
	data = pf_getdata(fl, as);
	va_end(as);
	return (data);
}

/*
** pf_fpargflag is responsible for handling the numeric flags such as
** mfw, prcn, and argument value.
*/

const char		*pf_fpargflag(const char *str, t_pfflag *fl)
{
	char	dot;
	int		nbr;

	dot = (*str == '.' ? 1 : 0);
	str += dot;
	nbr = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '$' && str++)
		fl->argf = nbr;
	else if (dot)
		fl->prcn = nbr;
	else
		fl->mfw = nbr;
	return (str);
}
