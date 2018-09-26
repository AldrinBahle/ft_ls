/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list_details.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:09:34 by agama             #+#    #+#             */
/*   Updated: 2018/08/20 09:20:25 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		display_list_details(t_file *begin, int flags)
{
	int	size[7];
	int	blocks;
	int	first;

	ft_bzero(size, sizeof(size));
	blocks = 0;
	first = 1;
	get_row_size(begin, size, &blocks);
	while (begin)
	{
		if (first == 1 && !(flags & LS_D))
		{
			ft_printf("total %d\n", blocks);
			first = 0;
		}
		display_list_contents(begin, size, flags);
		ft_putchar('\n');
		begin = begin->next;
	}
	return (1);
}
