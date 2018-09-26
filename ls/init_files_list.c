/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:40:43 by agama             #+#    #+#             */
/*   Updated: 2018/08/31 08:14:43 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*init_files_list(int argc, char **argv, int first)
{
	t_file	*begin;
	int		i;

	begin = NULL;
	(!argc) ? add_new_file("", ".", &begin)
		: ft_sort_tab(argv, argc, &ft_strcmp);
	i = -1;
	while (++i < argc)
		if (add_new_file("", argv[i], &begin) == -1 && first)
			ls_error(argv[i], ERRNO);
	return (begin);
}
