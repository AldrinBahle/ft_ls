/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:55:40 by agama             #+#    #+#             */
/*   Updated: 2018/08/15 16:09:43 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int			analyze_options(char *s, int *flags)
{
	int		n;

	while (*(++s))
	{
		if ((n = ft_strchr_index("alRrtdG1Ss", *s)) == -1)
			ls_error(s, USAGE);
		*flags |= (1 << n);
		if ((*s == 'l') || (*s == '1'))
			*flags &= (*s == 'l') ? ~LS_ONE : ~LS_L;
	}
	return (1);
}
