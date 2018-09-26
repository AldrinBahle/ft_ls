/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:43:25 by agama             #+#    #+#             */
/*   Updated: 2018/08/15 15:55:06 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parsing(int argc, char **argv, int *flags)
{
	int	i;

	*flags = 0;
	i = 0;
	while (++i < argc && argv[1][0] == '-' && argv[i][1])
	{
		if (argv[i][1] == '-' && argv[i][2])
			return (i + 1);
		if (!analyze_options(argv[i], flags))
			return (-1);
	}
	return (i);
}
