/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_row_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:07:45 by agama             #+#    #+#             */
/*   Updated: 2018/08/20 09:45:17 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_row_size(t_file *begin, int size[6], int *blocks)
{
	int	len;

	size[5] = 3;
	size[6] = 3;
	while (begin)
	{
		size[0] = MAX(integer_len(begin->st_blocks), size[0]);
		size[1] = MAX(integer_len(begin->st_nlink), size[1]);
		size[2] = MAX(ft_strlen(getpwuid(begin->st_uid)->pw_name), size[2]);
		size[3] = MAX(ft_strlen(getgrgid(begin->st_gid)->gr_name), size[3]);
		if (!S_ISCHR(begin->mode))
			len = integer_len(begin->size);
		else
		{
			size[5] = MAX(integer_len(major(begin->st_rdev)), size[5]);
			size[6] = MAX(integer_len(minor(begin->st_rdev)), size[6]);
			len = size[5] + size[6] + 2;
		}
		size[4] = MAX(len, size[4]);
		*blocks += begin->st_blocks;
		begin = begin->next;
	}
	size[5] = MAX(size[4] - size[6] - 1, size[5]);
	return (1);
}
